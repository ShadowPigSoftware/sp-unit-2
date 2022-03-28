#pragma once

#include "spunit_core.hpp"
#include "../expect_scenario.hpp"
#include "../expect_failure_message.hpp"
#include "../types/expect_type.hpp"
#include "expect_contain_test.hpp"

namespace SPUnit {
    template <class TActual, class TContain, class Enabler = void> class ExpectContainContainsMethod {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, bool iterable, bool invertLogic) {
            Internal::unused(actual, value, iterable, invertLogic);
            if (iterable) {
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainNoIteratorNoContains(actual, value), line);
            }
            else {
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainNotIterableNoContains(actual, value), line);
            }
        }
    };

     template <class TActual, class TContain> class ExpectContainContainsMethod<TActual, TContain, typename std::enable_if<ExpectContainTest::containsMethodSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, bool iterable, bool invertLogic) {
            Internal::unused(iterable);
            if ((!actual.contains(value)) != invertLogic) { //!= acts as logical XOR
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainCannotFind(actual, value, invertLogic), line);
            }
        }
    };
}