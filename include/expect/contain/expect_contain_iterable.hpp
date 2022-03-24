#pragma once

#include "spunit_core.hpp"
#include "../expect_scenario.hpp"
#include "../expect_failure_message.hpp"
#include "../types/expect_type.hpp"
#include "expect_contain_test.hpp"
#include "expect_contain_iterator.hpp"
#include "expect_contain_contains_method.hpp"

namespace SPUnit {
    template <class TActual, class TContain, class Enabler = void> class ExpectContainIterable {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainContainsMethod<TActual, TContain>::run(scenario, line, actual, value, false);
        }
    };

     template <class TActual, class TContain> class ExpectContainIterable<TActual, TContain, typename std::enable_if<ExpectContainTest::iterableSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainIterator<TActual, TContain>::run(scenario, line, actual, value);
        }
    };
}