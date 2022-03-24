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
    //expect("abc").to.contain('c');
    //expect("abc").to.contain("ab");
    //expect({1,2,3,4}).to.contain(1);


    // template <class TActual, class TContain, class Enabler = void> class ExpectContainFind {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, const std::string& fallback) {
    //         Internal::unused(actual, value);
    //         ExpectScenario::fail(scenario, fallback, line);
    //     }
    // };

    // template <class TActual, class TContain> class ExpectContainFind<TActual, TContain, typename std::enable_if<ExpectContainTest::findMethodSupported<TActual, TContain>::value>::type> {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value, const std::string& fallback) {
    //         Internal::unused(actual, value, fallback);
    //         if (!actual.find(value))
    //         {
    //             ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainCannotFind(actual, value), line);
    //         }
    //     }
    // };
    
    // template <class TActual, class TContain, class Enabler = void> class ExpectContainIterator {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
    //         ExpectContainFind<TActual, TContain>::run(scenario, line, actual, value, ExpectFailureMessage::makeContainValueNotComparable(actual, value));
    //     }
    // };

    // template <class TActual, class TContain> class ExpectContainIterator<TActual, TContain, typename std::enable_if<ExpectContainTest::iteratorValueCompareSupported<TActual, TContain>::value>::type> {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
    //         for (auto rangeValue: actual) {
    //             if (rangeValue == value) {
    //                 return;
    //             }
    //         }
    //         ExpectScenario::fail(scenario, ExpectFailureMessage::makeContain(actual, value), line);
    //     }
    // };
    
    // template <class TActual, class TContain, class Enabler = void> class ExpectContain {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
    //         ExpectContainFind<TActual, TContain>::run(scenario, line, actual, value, ExpectFailureMessage::makeContainNotIterable(actual));
    //     }
    // };

    // template <class TActual, class TContain> class ExpectContain<TActual, TContain, typename std::enable_if<ExpectContainTest::iterableSupported<TActual, TContain>::value>::type> {
    // public:
    //     using TActualParameterType = typename ExpectType<TActual>::ParameterType;
    //     using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
    //     static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
    //         ExpectContainIterator<TActual, TContain>::run(scenario, line, actual, value);
    //     }
    // };


    template <class TActual, class TContain, class Enabler = void> class ExpectContain {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainIterable<TActual, TContain>::run(scenario, line, actual, value);
        }
    };

    //This is a string
    template <class TActual, class TContain> class ExpectContain<TActual, TContain ,typename std::enable_if<ExpectContainTest::stringSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
           ExpectContainString<TActual, TContain>::run(scenario, line, actual, value);
        }
    };
}