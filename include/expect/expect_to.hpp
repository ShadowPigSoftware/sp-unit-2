#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
namespace SPUnit {
    class Scenario;

    template <class T> class ExpectTo {
    public:
        ExpectTo(Scenario& scenario, uint32_t line, T actual):
            _scenario {scenario},
            _line {line},
            _actual {actual}
        {}

        template <class U> void equal(const U& expected) const {
            if (expected != _actual) {
                ExpectScenario::fail(_scenario, "", _line);
            }
        }
    private:
        Scenario& _scenario; 
        uint32_t _line;
        T _actual;
    };
}