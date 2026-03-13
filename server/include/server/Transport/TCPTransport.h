#pragma once
#include "ITransport.h"
#include <boost/asio.hpp>

namespace server::transport {
    class TCPTransport : public ITransport{
    public:
        TCPTransport(boost::asio::ip::tcp::socket&& socket);
        void asyncRead(std::function<void(const std::string &)> handler) override;
        void asyncWrite(const std::string &data, std::function<void()> handler) override;
        void proccesMassage(std::function<void(const std::string&)> handler);
    private:
        boost::asio::ip::tcp::socket socket_;
        std::array<char, 4096> buffer_;
        std::string incoming_;

    };

}