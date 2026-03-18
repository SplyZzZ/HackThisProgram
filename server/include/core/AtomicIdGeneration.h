//
// Created by stas on 3/17/26.
//

#pragma once
#include <atomic>
#include "IIdGeneration.h"
namespace server {
    class AtomicIdGeneration : public IIdGeneration {
        public:
        uint64_t next() override;
    private:
        std::atomic<uint64_t> counter_{1};
    };
}