#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"

namespace SPUnit {
    //expect(actual).to.be.within(threshold).of(expected);
    //i.e. expected - threshold <= actual <= expected + threshold;
    //so lte <=, minux -, and plus + must be defined
    class ExpectThresholdTest {
    public:
        template <class TActual, class TExpected, class TThreshold> using CheckMinus = decltype(std::declval<TExpected>() - std::declval<TThreshold>());
        template <class TActual, class TExpected, class TThreshold> using CheckPlus = decltype(std::declval<TExpected>() + std::declval<TThreshold>());
        template <class TActual, class TExpected, class TThreshold> using CheckLowerBound = std::void_t<decltype(std::declval<CheckMinus<TActual, TExpected, TThreshold>>() <= std::declval<TActual>())>;
        template <class TActual, class TExpected, class TThreshold> using CheckUpperBound = std::void_t<decltype(std::declval<TActual>() <= std::declval<CheckPlus<TActual, TExpected, TThreshold>>())>;

        template <class TActual, class TExpected, class TThreshold, class = void>
        struct testLowerBound: public std::false_type {};
        
        template <class TActual, class TExpected, class TThreshold>
        struct testLowerBound<TActual, TExpected, TThreshold, CheckLowerBound<TActual, TExpected, TThreshold>>: public std::true_type {};

        template <class TActual, class TExpected, class TThreshold, class = void>
        struct testUpperBound: public std::false_type {};
        
        template <class TActual, class TExpected, class TThreshold>
        struct testUpperBound<TActual, TExpected, TThreshold, CheckUpperBound<TActual, TExpected, TThreshold>>: public std::true_type {};

        template <class TActual, class TExpected, class TThreshold> using supported = std::bool_constant<
            testLowerBound<TActual, TExpected, TThreshold>::value &&
            testUpperBound<TActual, TExpected, TThreshold>::value
        >;
    };

    
    template <class TActual, class TExpected, class TThreshold, class Enabler = void> class ExpectThreshold {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TExpectedParameterType = typename ExpectType<TExpected>::ParameterType;
        using TThresholdParameterType = typename ExpectType<TThreshold>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TExpectedParameterType expected, TThresholdParameterType threshold, bool invertLogic) {
            Internal::unused(actual, expected, threshold, invertLogic);
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeNoThresholdOperator(), line);
        }
    };

    template <class TActual, class TExpected, class TThreshold> class ExpectThreshold<TActual, TExpected, TThreshold, typename std::enable_if<ExpectThresholdTest::supported<TActual, TExpected, TThreshold>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TExpectedParameterType = typename ExpectType<TExpected>::ParameterType;
        using TThresholdParameterType = typename ExpectType<TThreshold>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TExpectedParameterType expected, TThresholdParameterType threshold, bool invertLogic) {
            Internal::unused(actual, expected, threshold);
            if ((!(((expected - threshold) <= actual) && (actual <= (expected + threshold)))) != invertLogic) { //!= acts as logical XOR
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeWithin(actual, expected, threshold, invertLogic), line);
            }
        }
    };
}