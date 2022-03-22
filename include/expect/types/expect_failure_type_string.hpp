


#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {

   template <> class ExpectFailureType<const char*> {
    public:
        static void stream(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };

    template <int L> class ExpectFailureType<char[L]> {
    public:
        static void stream(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };
}