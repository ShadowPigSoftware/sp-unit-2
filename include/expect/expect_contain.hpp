#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include "expect_difference.hpp"
#include "expect_comparison.hpp"
#include "contain/expect_contain_string.hpp"
#include "contain/expect_contain_iterable.hpp"
#include "contain/expect_contain_test.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    template <class TActual, class TContain, class Enabler = void> class ExpectContain {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainIterable<TActual, TContain>::run(scenario, line, actual, value);
        }
    };

    template <class TActual, class TContain> class ExpectContain<TActual, TContain ,typename std::enable_if<ExpectContainTest::stringSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
           ExpectContainString<TActual, TContain>::run(scenario, line, actual, value);
        }
    };
}