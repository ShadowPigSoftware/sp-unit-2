#pragma once

#include "spunit_core.hpp"
#include "expect_to_be_within.hpp"
#include "expect_comparison.hpp"
#include "expect_less_than.hpp"
#include "expect_greater_than.hpp"
#include "expect_less_than_or_equal.hpp"
#include "expect_greater_than_or_equal.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class Scenario;

    template <class T> class ExpectToBe {
    public:
        ExpectToBe(Scenario& scenario, uint32_t line, bool execute, typename ExpectType<T>::ParameterType actual, bool invertLogic):
            _scenario {scenario},
            _line {line},
            _execute {execute},
            _actual {actual},
            _invertLogic {invertLogic}
        {}

        template <class U> void equalTo(const U& expected) const {
            if (_execute) {
                ExpectComparison<T,U>::run(_scenario, _line, _actual, expected, _invertLogic); 
            }
        }

        template <class U> void lessThan(const U& expected) const {
            if (_execute) {
                ExpectLessThan<T,U>::run(_scenario, _line, _actual, expected, _invertLogic);
            }
        }

        template <class U> void greaterThan(const U& expected) const {
            if (_execute) {
                ExpectGreaterThan<T,U>::run(_scenario, _line, _actual, expected, _invertLogic);
            }
        }

        template <class U> void lessThanOrEqual(const U& expected) const {
            if (_execute) {
                ExpectLessThanOrEqual<T,U>::run(_scenario, _line, _actual, expected, _invertLogic);
            }
        }

        template <class U> void greaterThanOrEqual(const U& expected) const {
            if (_execute) {
                ExpectGreaterThanOrEqual<T,U>::run(_scenario, _line, _actual, expected, _invertLogic);
            }
        }

        template <class U> ExpectToBeWithin<T, U> within(const U& threshold) const {
            return ExpectToBeWithin<T, U>(_scenario, _line, _execute, _actual, threshold, _invertLogic);
        }
    private:
        Scenario& _scenario; 
        uint32_t _line;
        bool _execute;
        typename ExpectType<T>::StorageType _actual;
        bool _invertLogic;
    };
}