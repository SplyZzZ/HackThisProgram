//
// Created by stas on 3/17/26.
//
#include "server/TcpServer.h"

#include "core/AtomicIdGeneration.h"

namespace server {
    TcpServer::TcpServer(boost::asio::io_context &ioCotext, uint64_t port, std::shared_ptr<IIdGeneration> idGeneration) : ioContext_(ioCotext), acceptor_(ioContext_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), idGenerator_(idGeneration)
    {}

    TcpServer::TcpServer(boost::asio::io_context &ioCotext, uint64_t port) : ioContext_(ioCotext), acceptor_(ioContext_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
        idGenerator_ = std::make_shared<AtomicIdGeneration>();
    }

    void TcpServer::start() {
        doAccept();
    }

    void TcpServer::stop() {
    }

    void TcpServer::doAccept() {

    }
}
