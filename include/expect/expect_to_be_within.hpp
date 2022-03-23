#pragma once

#include "spunit_core.hpp"
#include "expect_comparison.hpp"
#include "expect_threshold.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class Scenario;

    template <class TActual, class TThreshold> class ExpectToBeWithin {
    public:
        ExpectToBeWithin(Scenario& scenario, uint32_t line, typename ExpectType<TActual>::ParameterType actual, typename ExpectType<TThreshold>::ParameterType threshold):
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
        typename ExpectType<TActual>::StorageType _actual;
        typename ExpectType<TThreshold>::StorageType _threshold;
    };
}