#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include <iostream>

namespace SPUnit {
    class Scenario;

    //expect(actual).to.be.within(threshold).of(expected);
    //i.e. expected - threshold <= actual <= expected + threshold;
    //so lte <=, minux -, and plus + must be defined
    class ExpectThresholdTest {
    public:
        template <class TActual, class TExpected, class TThreshold> using TMinus = decltype(std::declval<TExpected>() - std::declval<TThreshold>());
        template <class TActual, class TExpected, class TThreshold> using TPlus = decltype(std::declval<TExpected>() + std::declval<TThreshold>());
        template <class TActual, class TExpected, class TThreshold> using TLowerBound = decltype(std::declval<TMinus<TActual, TExpected, TThreshold>>() <= std::declval<TActual>());
        template <class TActual, class TExpected, class TThreshold> using TUpperBound = decltype(std::declval<TActual>() <= std::declval<TPlus<TActual, TExpected, TThreshold>>());

        template <class TActual, class TExpected, class TThreshold, class = TLowerBound<TActual, TExpected, TThreshold>>
        static constexpr std::true_type testLowerBound(const TActual&, const TExpected&, const TThreshold&);
        static constexpr std::false_type testLowerBound(...);

        template <class TActual, class TExpected, class TThreshold, class = TUpperBound<TActual, TExpected, TThreshold>>
        static constexpr std::true_type testUpperBound(const TActual&, const TExpected&, const TThreshold&);
        static constexpr std::false_type testUpperBound(...);


        template <class TActual, class TExpected, class TThreshold> using supportedLB = decltype(testLowerBound(std::declval<TActual>(), std::declval<TExpected>(), std::declval<TThreshold>()));
        template <class TActual, class TExpected, class TThreshold> using supportedUB = decltype(testUpperBound(std::declval<TActual>(), std::declval<TExpected>(), std::declval<TThreshold>()));
        template <class TActual, class TExpected, class TThreshold> using supported = std::bool_constant<
            supportedLB<TActual, TExpected, TThreshold>::value &&
            supportedUB<TActual, TExpected, TThreshold>::value
        >;
    };

    
    template <class TActual, class TExpected, class TThreshold, class Enabler = void> class ExpectThreshold {
    public:
        static void run(Scenario& scenario, uint32_t line, const TActual& actual, const TExpected& expected, const TThreshold& threshold) {
            Internal::unused(actual, expected, threshold);
            ExpectScenario::fail(scenario, "The threshold operator (e-t <= a <= e+t) is not supported on these objects", line);
        }
    };

    template <class TActual, class TExpected, class TThreshold> class ExpectThreshold<TActual, TExpected, TThreshold, typename std::enable_if<ExpectThresholdTest::supported<TActual, TExpected, TThreshold>::value>::type> {
    public:
        static void run(Scenario& scenario, uint32_t line, const TActual& actual, const TExpected& expected, const TThreshold& threshold) {
            Internal::unused(actual, expected, threshold);
            if (!(((expected - threshold) <= actual) && (actual <= (expected + threshold)))) {
                ExpectScenario::fail(scenario, ExpectFailureMessage::makeWithin(actual, expected, threshold), line);
            }
        }
    };
}