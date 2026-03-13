#include "server/Transport/ITransport.h"
#include "server/Transport/TCPTransport.h"
namespace server::transport {
    TCPTransport::TCPTransport(boost::asio::ip::tcp::socket&& socket) : socket_(std::move(socket))
    {}

    void TCPTransport::asyncRead(
        std::function<void(const std::string&)> handler
    )
    {
        socket_.async_read_some(
            boost::asio::buffer(buffer_),
            [this, handler](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    incoming_.append(buffer_.data(), length);
                    proccesMassage(handler);
                    asyncRead(handler);
                }
                else if (ec == boost::asio::error::eof) {
                    //TODO: Reaction to disconnection
                }

            });
    }
    void TCPTransport::proccesMassage(std::function<void(const std::string&)> handler) {

        while (true) {
            auto pos = incoming_.find("\n");
            
            if (pos == std::string::npos) {
                break;
            }
            handler(incoming_.substr(0, pos));
            incoming_.erase(0, pos+1);
        }
    }
}
