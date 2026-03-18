#include "server/transport/TCPTransport.h"
namespace server::transport {
    TCPTransport::TCPTransport(boost::asio::ip::tcp::socket&& socket) : socket_(std::move(socket))
    {}

    void TCPTransport::asyncRead(const std::function<void(const std::string&)>& handler)
    {
        auto self = shared_from_this();
        socket_.async_read_some(boost::asio::buffer(buffer_),
            [self, handler](const boost::system::error_code& ec, std::size_t length)
            {
                if (!ec)
                {
                    self->incoming_.append(self->buffer_.data(), length);
                    self->processMessage(handler);
                    self->asyncRead(handler);
                }
                else if (ec == boost::asio::error::eof) {
                    //TODO: Reaction to disconnection
                }

            });
    }
    void TCPTransport::processMessage(const std::function<void(const std::string&)>& handler) {

        while (true) {
            auto pos = incoming_.find('\n');

            if (pos == std::string::npos)
                break;

            handler(incoming_.substr(0, pos));
            incoming_.erase(0, pos+1);
        }
    }
    void TCPTransport::asyncWrite( std::string data, std::function<void()> handler)
    {
        auto self = shared_from_this();

        boost::asio::async_write(socket_, boost::asio::buffer(data),[self, data = std::move(data), handler = std::move(handler)]
            (const boost::system::error_code& ec, std::size_t)
            {
                if (!ec && handler)
                    handler();
            }
        );
    }
}