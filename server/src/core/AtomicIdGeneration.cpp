//
// Created by stas on 3/17/26.
//
#include "core/AtomicIdGeneration.h"
namespace server {
    uint64_t AtomicIdGeneration::next() {
        return counter_.fetch_add(1, std::memory_order_relaxed);
    }
}
