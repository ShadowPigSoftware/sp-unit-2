#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include "expect_difference.hpp"
#include "expect_comparison.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class Scenario;
    //expect("abc").to.contain('c');
    //expect("abc").to.contain("ab");
    //expect({1,2,3,4}).to.contain(1);

    class ExpectContainTest {
    public:
        template <class T> using CheckConstBegin = std::void_t<decltype(std::begin(std::declval<const T&>()))>;
        template <class T> using CheckConstEnd = std::void_t<decltype(std::begin(std::declval<const T&>()))>;

        template <class T, class = void>
        struct ConstBeginSupported: public std::false_type {};
        
        template <class T>
        struct ConstBeginSupported<T, CheckConstBegin<T>>: public std::true_type {};

        template <class T, class = void>
        struct ConstEndSupported: public std::false_type {};
        
        template <class T>
        struct ConstEndSupported<T, CheckConstEnd<T>>: public std::true_type {};

        template <class T> using BeginEndSupported = std::bool_constant<ConstBeginSupported<T>::value && ConstEndSupported<T>::value>;

        template <class TActual, class TContain, class = void>
        class IterableTest {
        public:
            using ConstBeginSupported = ExpectContainTest::ConstBeginSupported<TActual>;
            using ConstEndSupported = ExpectContainTest::ConstEndSupported<TActual>;
            using BeginEndComparableSupported = std::false_type;
            using IteratorValueComparable = std::false_type;
            using PreIncrementSupported = std::false_type;
            using DereferenceSupported = std::false_type;
        };

        template <class TActual, class TContain>
        class IterableTest<TActual, TContain, typename std::enable_if<BeginEndSupported<TActual>::value>::type> {//int can be anything but void
        public:
            using ConstBeginSupported = ExpectContainTest::ConstBeginSupported<TActual>;
            using ConstEndSupported = ExpectContainTest::ConstEndSupported<TActual>;
            using BeginEndComparableSupported = ExpectDifferenceTest::supported<decltype(std::begin(std::declval<const TActual&>())), decltype(std::begin(std::declval<const TActual&>()))>;

            struct Internal {
                using IteratorType = decltype(std::begin(std::declval<const TActual&>()));
                using CheckPreIncrement = std::void_t<decltype(++std::declval<IteratorType&>())>;
                using CheckDereference = std::void_t<decltype(*std::declval<IteratorType&>())>;

                //cannot place explicit specialisation inside class, therefore use a throwaway type TUnused to allow
                //partial specialisation, which is allowed in a class
                template <class TUnused, class = void>
                struct PreIncrementSupported: public std::false_type {};
            
                template <class TUnused>
                struct PreIncrementSupported<TUnused, CheckPreIncrement>: public std::true_type {};

                template <class TUnused, class = void>
                struct DereferenceSupported: public std::false_type 
                {
                    using IteratorValueComparable = std::false_type;
                };
            
                template <class TUnused>
                struct DereferenceSupported<TUnused, CheckDereference>: public std::true_type 
                {
                    using DereferenceType = decltype(*std::declval<IteratorType&>());
                    using IteratorValueComparable = ExpectComparisonTest::supported<DereferenceType, TContain>;
                };
            };

            using IteratorValueComparable = typename Internal::DereferenceSupported<void>::IteratorValueComparable;
            using PreIncrementSupported = typename Internal::PreIncrementSupported<void>;
            using DereferenceSupported = typename Internal::DereferenceSupported<void>;
        };

        template <class TActual, class TContain> using iterableSupported = std::bool_constant<
            IterableTest<TActual, TContain>::ConstBeginSupported::value &&
            IterableTest<TActual, TContain>::ConstEndSupported::value &&
            IterableTest<TActual, TContain>::BeginEndComparableSupported::value &&
            IterableTest<TActual, TContain>::PreIncrementSupported::value &&
            IterableTest<TActual, TContain>::DereferenceSupported::value
        >;

        template <class TActual, class TContain> using iteratorValueCompareSupported = typename IterableTest<TActual, TContain>::IteratorValueComparable;
    };

    template <class TActual, class TContain, class Enabler = void> class ExpectContainIterator {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            Internal::unused(actual, value);
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainValueNotComparable(actual, value), line);
        }
    };

    template <class TActual, class TContain> class ExpectContainIterator<TActual, TContain, typename std::enable_if<ExpectContainTest::iteratorValueCompareSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            for (auto rangeValue: actual) {
                if (rangeValue == value) {
                    return;
                }
            }
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeContain(actual, value), line);
        }
    };
    
    template <class TActual, class TContain, class Enabler = void> class ExpectContain {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            Internal::unused(value);
            ExpectScenario::fail(scenario, ExpectFailureMessage::makeContainNotIterable(actual), line);
        }
    };

    template <class TActual, class TContain> class ExpectContain<TActual, TContain, typename std::enable_if<ExpectContainTest::iterableSupported<TActual, TContain>::value>::type> {
    public:
        using TActualParameterType = typename ExpectType<TActual>::ParameterType;
        using TContainParameterType = typename ExpectType<TContain>::ParameterType;
        
        static void run(Scenario& scenario, uint32_t line, TActualParameterType actual, TContainParameterType value) {
            ExpectContainIterator<TActual, TContain>::run(scenario, line, actual, value);
        }
    };
}