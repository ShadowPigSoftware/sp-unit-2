#pragma once

#include "spunit_core.hpp"

#include <sstream>

namespace SPUnit {
    template <class T> class ExpectFailureType {
    public:
        static void stream(std::stringstream& ss, const T& value) {
            ss << value;
        }
    };
}