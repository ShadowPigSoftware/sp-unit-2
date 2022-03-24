 #pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class ExpectContainContainsMethodTest {
    public:
        template <class TActual, class TContain> using Check = std::void_t<decltype(std::declval<TActual>().contains(std::declval<TContain>()))>;

        template <class TActual, class TContain, class = void>
        struct ContainsReturnType{
            template <class TUnused>
            struct supported: std::false_type{};
        };
        
        template <class TActual, class TContain>
        struct ContainsReturnType<TActual, TContain, Check<TActual, TContain>> {
            using ReturnType = decltype(std::declval<TActual>().contains(std::declval<TContain>()));
            using CheckForBooleanCast = std::void_t<decltype(static_cast<bool>(std::declval<ReturnType>()))>;

            template <class TUnused, class = void>
            struct supported: std::false_type{};
                
            template <class TUnused>
            struct supported<TUnused, CheckForBooleanCast>: std::true_type{};
        };

        template <class TActual, class TContain> using supported = typename ContainsReturnType<TActual, TContain>::supported<void>;
    };
}