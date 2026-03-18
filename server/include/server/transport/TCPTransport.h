#pragma once
#include "ITransport.h"
#include <boost/asio.hpp>

namespace server::transport {
    class TCPTransport : public ITransport, public std::enable_shared_from_this<TCPTransport>{
    public:
        TCPTransport(boost::asio::ip::tcp::socket&& socket);
        void asyncRead( const std::function<void(const std::string &)>& handler) override;
        void asyncWrite(std::string data, std::function<void()> handler) override;
        void processMessage(const std::function<void(const std::string&)>& handler);
    private:
        boost::asio::ip::tcp::socket socket_;
        std::array<char, 4096> buffer_;
        std::string incoming_;

    };

}