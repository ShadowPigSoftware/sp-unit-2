#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class ExpectStreamableTest {
    public:
        template <class T> using Check = std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>;

        template <class T, class = void>
        struct supported: public std::false_type {};
        
        template <class T>
        struct supported<T, Check<T>>: public std::true_type {};
    };
}