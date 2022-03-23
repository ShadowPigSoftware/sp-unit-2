#pragma once

#include "spunit_core.hpp"
#include "types/expect_failure_types.hpp"

#include <sstream>

namespace SPUnit {
    class ExpectFailureMessage {
    public:
        template <class T, class U> static std::string makeEqual(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            ss << " to equal ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeLessThan(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            ss << " to be less than ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeGreaterThan(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            ss << " to be greater than ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

         template <class T, class U> static std::string makeLessThanOrEqual(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            ss << " to be less than or equal to ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeGreaterThanOrEqual(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            ss << " to be greater than or equal to";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class TActual, class TExpected, class TThreshold> static std::string makeWithin(const TActual& actual, const TExpected& expected, const TThreshold& threshold) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<TActual>::stream(ss, actual);
            ss << " to be within ";
            ExpectFailureType<TThreshold>::stream(ss, threshold);
            ss << " of ";
            ExpectFailureType<TExpected>::stream(ss, expected);
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContain(const TActual& actual, const TContain& contain) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<TActual>::stream(ss, actual);
            ss << " to contain ";
            ExpectFailureType<TContain>::stream(ss, contain);
            return ss.str();
        }
    };
}