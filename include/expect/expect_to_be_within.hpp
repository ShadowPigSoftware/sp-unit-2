#pragma once

#include "spunit_core.hpp"
#include "expect_comparison.hpp"
#include "expect_threshold.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class Scenario;

    template <class TActual, class TThreshold> class ExpectToBeWithin {
    public:
        ExpectToBeWithin(Scenario& scenario, uint32_t line, bool execute, typename ExpectType<TActual>::ParameterType actual, typename ExpectType<TThreshold>::ParameterType threshold, bool invertLogic):
            _scenario {scenario},
            _line {line},
            _execute {execute},
            _actual {actual},
            _threshold {threshold},
            _invertLogic {invertLogic}
        {}

        template <class U> void of(const U& expected) const {
            if (_execute)
            {
                ExpectThreshold<TActual,U, TThreshold>::run(_scenario, _line, _actual, expected, _threshold, _invertLogic);
            }
        }
    private:
        Scenario& _scenario; 
        uint32_t _line;
        bool _execute;
        typename ExpectType<TActual>::StorageType _actual;
        typename ExpectType<TThreshold>::StorageType _threshold;
        bool _invertLogic;
    };
}