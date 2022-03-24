 #pragma once

#include "spunit_core.hpp"
#include "../expect_difference.hpp"
#include "../expect_comparison.hpp"

namespace SPUnit {
    class ExpectContainIterableTest {
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

        template <class TActual, class = void>
        class IterableTest {
        public:
            using BeginEndComparableSupported = std::false_type;
            using PreIncrementSupported = std::false_type;
            using DereferenceSupported = std::false_type;
        };

        template <class TActual>
        class IterableTest<TActual, typename std::enable_if<BeginEndSupported<TActual>::value>::type> {//int can be anything but void
        public:
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
                struct DereferenceSupported: public std::false_type {};
            
                template <class TUnused>
                struct DereferenceSupported<TUnused, CheckDereference>: public std::true_type {};
            };

            using PreIncrementSupported = typename Internal::PreIncrementSupported<void>;
            using DereferenceSupported = typename Internal::DereferenceSupported<void>;
        };

        template <class TActual, class TContainUnused> using supported = std::bool_constant<
            ConstBeginSupported<TActual>::value &&
            ConstEndSupported<TActual>::value &&
            IterableTest<TActual>::BeginEndComparableSupported::value &&
            IterableTest<TActual>::PreIncrementSupported::value &&
            IterableTest<TActual>::DereferenceSupported::value
        >;
    };
}