#pragma once

#include "spunit_core.hpp"
#include "expect_comparison.hpp"
#include "expect_threshold.hpp"

#include <iostream>

namespace SPUnit {
    class Scenario;

    template <class TActual, class TThreshold> class ExpectToBeWithin {
    public:
        ExpectToBeWithin(Scenario& scenario, uint32_t line, TActual actual, TThreshold threshold):
            _scenario {scenario},
            _line {line},
            _actual {actual},
            _threshold {threshold}
        {}

        template <class U> void of(const U& expected) const {
            ExpectThreshold<TActual,U, TThreshold>::run(_scenario, _line, _actual, expected, _threshold);            
        }
    private:
        Scenario& _scenario; 
        uint32_t _line;
        TActual _actual;
        TThreshold _threshold;
    };
}