


#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {
   template <> class ExpectFailureStreamableType<char> {
    public:
        static void stream(std::stringstream& ss, char value) {
            ss << "\'" << value << "\'(0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value) << ")";
        }
    };
}