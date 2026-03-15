#include "core/MessageQueue.h"
namespace server::message {
    void MessageQueue::push(Message&& message) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            messageQueue_.push(std::move(message));
        }
        cv_.notify_one();
    }
    Message MessageQueue::pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return !messageQueue_.empty(); });
        auto msg = std::move(messageQueue_.front());
        messageQueue_.pop();
        return msg;
    }
}