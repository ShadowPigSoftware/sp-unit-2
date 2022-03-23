


#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {
    template <> class ExpectFailureStreamableType<uint8_t> {
    public:
        static void stream(std::stringstream& ss, uint8_t value) {
            ss << static_cast<int>(value);
        }
    };

    template <int L> class ExpectFailureStreamableType<uint8_t[L]> {
    public:
        using Array = uint8_t[L];
        static void stream(std::stringstream& ss, const Array& value) {
            bool comma = false;
            ss << "{";
            for (auto item: value) {
                if (comma) {
                    ss << ",";
                } else {
                    comma = true;
                }
                ss << static_cast<int>(item);
            }
            ss << "}";
        }
    };
}