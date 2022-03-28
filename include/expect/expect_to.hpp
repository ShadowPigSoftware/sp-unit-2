#pragma once

#include "spunit_core.hpp"
#include "expect_to_be.hpp"
#include "expect_comparison.hpp"
#include "expect_contain.hpp"
#include "types/expect_type.hpp"


namespace SPUnit {
    class Scenario;

    template <class T> class ExpectTo {
    public:
        ExpectTo(Scenario& scenario, uint32_t line, bool execute, typename ExpectType<T>::ParameterType actual, bool invertLogic = false):
            be {scenario, line, execute, actual, invertLogic},
            _scenario {scenario},
            _line {line},
            _execute {execute},
            _actual {actual},
            _invertLogic {invertLogic}
        {}

        template <class U> void equal(const U& expected) const {
            if (_execute) {
                ExpectComparison<T,U>::run(_scenario, _line, _actual, expected, _invertLogic);
            }
        }

        template <class U> void contain(const U& value) const {
            if (_execute) {
                ExpectContain<T,U>::run(_scenario, _line, _actual, value, _invertLogic);
            }
        }
        ExpectToBe<T> be;
    private:
        Scenario& _scenario; 
        uint32_t _line;
        bool _execute;
        typename ExpectType<T>::StorageType _actual;
        bool _invertLogic;
    };
}