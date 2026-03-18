//
// Created by stas on 3/17/26.
//

#pragma once
namespace server {
    class IServer {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual ~IServer() = default;
    };
}