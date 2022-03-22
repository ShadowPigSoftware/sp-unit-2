#pragma once

#include "spunit_core.hpp"
#include "expect_to_be.hpp"
#include "expect_comparison.hpp"

#include <iostream>

namespace SPUnit {
    class Scenario;

    template <class T> class ExpectTo {
    public:
        ExpectTo(Scenario& scenario, uint32_t line, T actual):
            be {scenario, line, actual},
            _scenario {scenario},
            _line {line},
            _actual {actual}
        {}

        template <class U> void equal(const U& expected) const {
            ExpectComparison<T,U>::run(_scenario, _line, _actual, expected);            
        }
        ExpectToBe<T> be;
    private:
        Scenario& _scenario; 
        uint32_t _line;
        T _actual;
    };
}