 #pragma once

#include "spunit_core.hpp"
#include "expect_contain_iterable_test.hpp"
namespace SPUnit {
    class ExpectContainIteratorTest {
    public:
        template <class TActual, class TContain, class = void>
        struct Internal {
            using compareSupported = std::false_type;
        };

        template <class TActual, class TContain>
        struct Internal<TActual, TContain, typename std::enable_if<ExpectContainIterableTest::supported<TActual, TContain>::value>::type> {
            using IteratorType = decltype(std::begin(std::declval<const TActual&>()));
            using DereferenceType = decltype(*std::declval<IteratorType&>());
            using IteratorValueComparable = ExpectComparisonTest::supported<DereferenceType, TContain>;
        };

        template <class TActual, class TContain> using supported = typename Internal<TActual, TContain>::IteratorValueComparable;
    };
}