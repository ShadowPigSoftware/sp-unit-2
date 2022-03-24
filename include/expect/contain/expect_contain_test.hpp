 #pragma once

#include "spunit_core.hpp"
#include "expect_contain_iterable_test.hpp"
#include "expect_contain_iterator_test.hpp"
#include "expect_contain_string_test.hpp"
#include "expect_contain_string_find_test.hpp"
#include "expect_contain_contains_method_test.hpp"

namespace SPUnit {
    class ExpectContainTest {
    public:
        template <class TActual, class TContain> using iterableSupported = typename ExpectContainIterableTest::supported<TActual, TContain>;

        template <class TActual, class TContain> using iteratorSupported = typename ExpectContainIteratorTest::supported<TActual, TContain>;

        template <class TActual, class TContain> using stringSupported = typename ExpectContainStringTest::supported<TActual, TContain>;

        template <class TActual, class TContain> using stringFindSupported = typename ExpectContainStringFindTest::supported<TActual, TContain>;

        template <class TActual, class TContain> using containsMethodSupported = typename ExpectContainContainsMethodTest::supported<TActual, TContain>;
    };
}