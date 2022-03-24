#pragma once

#include "spunit_core.hpp"
#include "../expect_scenario.hpp"
#include "../expect_failure_message.hpp"
#include "../types/expect_type.hpp"
#include "expect_contain_test.hpp"


namespace SPUnit {
    template <class TActual, class TContain, class Enabler = void> class ExpectContainString {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainNoStringFind(actual, value), line);
        }
    };

     template <class TActual, class TContain> class ExpectContainString<TActual, TContain, typename std::enable_if<ExpectContainTest::stringFindSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            if (actual.find(value) == std::string::npos) {
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainCannotFind(actual, value), line);
            }
        }
    };
}