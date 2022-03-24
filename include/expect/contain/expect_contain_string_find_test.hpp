 #pragma once

#include "spunit_core.hpp"
#include "expect_contain_string_test.hpp"

#include <string>
namespace SPUnit {
    class ExpectContainStringFindTest {
    public:
        template <class TContain> using CheckChar = std::is_same<TContain, char>;
        template <class TContain> using CheckCString = std::is_same<TContain, const char*>;
        template <class TContain> using CheckArray = std::bool_constant<
            CheckChar<typename std::remove_all_extents<TContain>::type>::value && std::is_array<TContain>::value
        >;
        template <class TContain> using CheckString = std::is_same<TContain, std::string>;

        template <class TContain, class = void>
        struct isChar: std::false_type {};

        template <class TContain>
        struct isChar<TContain, typename std::enable_if<CheckChar<TContain>::value>::type>: std::true_type {};

        template <class TContain, class = void>
        struct isCString: std::false_type {};

        template <class TContain>
        struct isCString<TContain, typename std::enable_if<CheckCString<TContain>::value>::type>: std::true_type {};

        template <class TContain, class = void>
        struct isCharArray: std::false_type {};

        template <class TContain>
        struct isCharArray<TContain, typename std::enable_if<CheckArray<TContain>::value>::type>: std::true_type {};

        template <class TContain, class = void>
        struct isString: std::false_type {};

        template <class TContain>
        struct isString<TContain, typename std::enable_if<CheckString<TContain>::value>::type>: std::true_type {};

        template <class TActual, class TContain, class = void>
        struct Internal {
            using findSupported = std::false_type;
        };

        template <class TActual, class TContain>
        struct Internal<TActual, TContain, typename std::enable_if<ExpectContainStringTest::supported<TActual, TContain>::value>::type> {        
            using findSupported = std::bool_constant<
               isChar<TContain>::value || isCString<TContain>::value || isCharArray<TContain>::value || isString<TContain>::value
            >;
        };

        template <class TActual, class TContain> using supported = typename Internal<TActual, TContain>::findSupported;
    };
}