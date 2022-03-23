


#pragma once

#include "expect_failure_type.hpp"

namespace SPUnit {

    template <> class ExpectFailureStreamableType<const char*> {
    public:
        static void stream(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };

    template <int L> class ExpectFailureStreamableType<char[L]> {
    public:
        static void stream(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };

    template <> class ExpectFailureStreamableType<std::string> {
    public:
        static void stream(std::stringstream& ss, const std::string& value) {
            ss << "\"" << value << "\"";
        }
    };
}