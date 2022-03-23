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
        ExpectTo(Scenario& scenario, uint32_t line, typename ExpectType<T>::ParameterType actual):
            be {scenario, line, actual},
            _scenario {scenario},
            _line {line},
            _actual {actual}
        {}

        template <class U> void equal(const U& expected) const {
            ExpectComparison<T,U>::run(_scenario, _line, _actual, expected);            
        }

        template <class U> void contain(const U& value) const {
            ExpectContain<T,U>::run(_scenario, _line, _actual, value);            
        }
        ExpectToBe<T> be;
    private:
        Scenario& _scenario; 
        uint32_t _line;
        typename ExpectType<T>::StorageType _actual;
    };
}