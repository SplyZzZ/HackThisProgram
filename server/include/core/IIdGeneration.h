//
// Created by stas on 3/17/26.
//

#pragma once
#include <cstdint>

namespace server {
    class  IIdGeneration {
    public:
        virtual uint64_t next() = 0;
        virtual ~IIdGeneration() = default;
    };
}
