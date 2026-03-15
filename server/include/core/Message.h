#pragma once
#include <cstdint>
#include <string>
namespace server::message {
    struct Message {
        uint64_t sessionID_;
        std::string data_;
    };
}