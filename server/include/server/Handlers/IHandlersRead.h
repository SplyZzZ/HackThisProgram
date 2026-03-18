#pragma once
#include "core/Message.h"
namespace server::handlers {
    class IHandlersRead {
    public:
        virtual void handler(message::Message&& message) = 0;
        virtual ~IHandlersRead();
    };
}