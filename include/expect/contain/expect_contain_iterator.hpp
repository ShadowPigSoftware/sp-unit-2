#pragma once

#include "spunit_core.hpp"
#include "../expect_scenario.hpp"
#include "../expect_failure_message.hpp"
#include "../types/expect_type.hpp"
#include "expect_contain_test.hpp"
#include "expect_contain_contains_method.hpp"

namespace SPUnit {
    template <class TActual, class TContain, class Enabler = void> class ExpectContainIterator {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainContainsMethod<TActual, TContain>::run(scenario, line, actual, value, true);
        }
    };

     template <class TActual, class TContain> class ExpectContainIterator<TActual, TContain, typename std::enable_if<ExpectContainTest::iteratorSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            Internal::unused(actual, value);
            for (auto item: actual) {
                if (item == value) {
                    return;
                }
            }
            ExpectScenario::fail(scenario, "could not find item in list", line);
            //ExpectScenario::fail(scenario, "String find implemented", line);
        }
    };
}