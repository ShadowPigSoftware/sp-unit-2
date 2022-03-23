#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {
    template <class T, int L> class ExpectFailureStreamableType<T[L]> {
    public:
        using Array = T[L];
        static void stream(std::stringstream& ss, const Array& value) {
            bool comma = false;
            ss << "{";
            for (auto item: value) {
                if (comma) {
                    ss << ",";
                } else {
                    comma = true;
                }
                ExpectFailureStreamableType<T>::stream(ss, item);
            }
            ss << "}";
        }
    };
}