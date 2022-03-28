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
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, bool invertLogic) {
            ExpectContainContainsMethod<TActual, TContain>::run(scenario, line, actual, value, true, invertLogic);
        }
    };

     template <class TActual, class TContain> class ExpectContainIterator<TActual, TContain, typename std::enable_if<ExpectContainTest::iteratorSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, bool invertLogic) {
            Internal::unused(actual, value);
            bool itemFound = false;
            for (auto item: actual) {
                if (item == value) {
                    itemFound = true;
                    break;
                }
            }
            if (itemFound != invertLogic) { // != acts as logical XOR
                return;
            }
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainCannotFind(actual, value, invertLogic), line);
        }
    };
}