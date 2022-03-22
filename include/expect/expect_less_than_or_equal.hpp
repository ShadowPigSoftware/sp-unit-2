#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include <iostream>

namespace SPUnit {
    class Scenario;

    class ExpectLessThanOrEqualTest {
    public:
        template <class T, class U, class = decltype(std::declval<T>() <= std::declval<U>())>
        static std::true_type test(const T&, const U&);
        static std::false_type test(...);

        template <class T, class U> using supported = decltype(test(std::declval<T>(), std::declval<U>()));
    };

    
    template <class T, class U, class Enabler = void> class ExpectLessThanOrEqual {
    public:
        static void run(Scenario& scenario, uint32_t line, const T& actual, const U& expected) {
            Internal::unused(actual, expected);
            ExpectScenario::fail(scenario, "The less than or equal operator (<=) is not supported on these objects", line);
        }
    };

    template <class T, class U> class ExpectLessThanOrEqual<T, U, typename std::enable_if<ExpectLessThanOrEqualTest::supported<T,U>::value>::type> {
    public:
        static void run(Scenario& scenario, uint32_t line, const T& actual, const U& expected) {
            if (!(actual < expected)) {
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeLessThanOrEqual(actual, expected), line);
            }
        }
    };
}