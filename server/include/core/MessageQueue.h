#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Message.h"
namespace server::message {
    class MessageQueue final {
    public:
        void push(Message&& message);
        Message pop();

    private:
        std::queue<Message> messageQueue_;
        std::mutex mutex_;
        std::condition_variable cv_;
    };
}
