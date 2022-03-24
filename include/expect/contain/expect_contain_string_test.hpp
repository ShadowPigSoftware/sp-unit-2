 #pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class ExpectContainStringTest {
    public:
        template <class TActual, class TContain> using supported = typename std::is_same<TActual, std::string>;
    };
}