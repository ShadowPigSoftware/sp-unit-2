


#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {
    template <> class ExpectFailureStreamableType<uint8_t> {
    public:
        static void stream(std::stringstream& ss, uint8_t value) {
            ss << static_cast<int>(value);
        }
    };
}