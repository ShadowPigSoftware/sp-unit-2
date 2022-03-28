#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class ExpectComparisonTest {
    public:
        template <class T, class U> using Check = std::void_t<decltype(std::declval<T>() == std::declval<U>())>;

        template <class T, class U, class = void>
        struct supported: public std::false_type {};
        
        template <class T, class U>
        struct supported<T, U, Check<T,U>>: public std::true_type {};
    };

    template <class T, class U, class Enabler = void> class ExpectComparison {
    public:
        using TParameterType = typename ExpectType<T>::ParameterType;
        using UParameterType = typename ExpectType<U>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TParameterType actual, UParameterType expected, bool invertLogic) {
            Internal::unused(actual, expected, invertLogic);
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeNoComparisonOperator(), line);
        }
    };

    template <class T, class U> class ExpectComparison<T, U, typename std::enable_if<ExpectComparisonTest::supported<T,U>::value>::type> {
    public:
        using TParameterType = typename ExpectType<T>::ParameterType;
        using UParameterType = typename ExpectType<U>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TParameterType actual, UParameterType expected, bool invertLogic) {
            if ((!(actual == expected)) != invertLogic) { //!= acts as logical XOR
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeEqual(actual, expected, invertLogic), line);
            }
        }
    };
}