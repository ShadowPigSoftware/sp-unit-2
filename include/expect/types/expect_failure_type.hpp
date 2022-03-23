#pragma once

#include "spunit_core.hpp"
#include "../expect_streamable.hpp"
#include <sstream>

namespace SPUnit {
    template <class T, class = void> class ExpectFailureType {
    public:
        static void stream(std::stringstream& ss, const T& value) {
            Internal::unused(value);
            ss << "[Unstreamable Value]";
        }
    };

    template <class T> 
    class ExpectFailureStreamableType {
    public:
        static void stream(std::stringstream& ss, const T& value) {
            ss << value;
        }
    };

    template <class T> 
    class ExpectFailureType<T, typename std::enable_if<ExpectStreamableTest::supported<T>::value>::type> {
    public:
        static void stream(std::stringstream& ss, const T& value) {
            ExpectFailureStreamableType<T>::stream(ss, value);
        }
    };
}