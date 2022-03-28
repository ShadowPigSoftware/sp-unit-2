#pragma once

#include "spunit_core.hpp"
#include "types/expect_failure_types.hpp"

#include <sstream>

namespace SPUnit {
    class ExpectFailureMessage {
    public:
        template <class T, class U> static std::string makeEqual(const T& actual, const U& expected, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to equal ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeLessThan(const T& actual, const U& expected, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to be less than ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeGreaterThan(const T& actual, const U& expected, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to be greater than ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

         template <class T, class U> static std::string makeLessThanOrEqual(const T& actual, const U& expected, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to be less than or equal to ";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class T, class U> static std::string makeGreaterThanOrEqual(const T& actual, const U& expected, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to be greater than or equal to";
            ExpectFailureType<U>::stream(ss, expected);
            return ss.str();
        }

        template <class TActual, class TExpected, class TThreshold> static std::string makeWithin(const TActual& actual, const TExpected& expected, const TThreshold& threshold, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<TActual>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to be within ";
            ExpectFailureType<TThreshold>::stream(ss, threshold);
            ss << " of ";
            ExpectFailureType<TExpected>::stream(ss, expected);
            return ss.str();
        }

        static std::string makeNoOperator(const std::string& name, const std::string& operatorString);
        static std::string makeNoComparisonOperator();
        static std::string makeNoDifferenceOperator();
        static std::string makeNoGreaterThanOrEqualOperator();
        static std::string makeNoGreaterThanOperator();
        static std::string makeNoLessThanOrEqualOperator();
        static std::string makeNoLessThanOperator();
        static std::string makeNoThresholdOperator();

        template <class TActual, class TContain> static std::string makeContain(const TActual& actual, const TContain& contain, bool invertLogic) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<TActual>::stream(ss, actual);
            if (invertLogic) {
                ss << " not";
            }
            ss << " to contain ";
            ExpectFailureType<TContain>::stream(ss, contain);
            return ss.str();
        }

        template <class TActual> static std::string makeContainNotIterable(const TActual& actual) {
            std::stringstream ss;
            ExpectFailureType<TActual>::stream(ss, actual);
            ss << " is not iterable";
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContainValueNotComparable(const TActual& actual, const TContain& contain) {
            std::stringstream ss;
            ss << "Cannot compare ";
            ExpectFailureType<TContain>::stream(ss, contain);
            ss << " against values in ";
            ExpectFailureType<TActual>::stream(ss, actual);
            ss << ": No valid comparison (==) operator";
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContainCannotFind(const TActual& actual, const TContain& contain, bool invertLogic) {
            std::stringstream ss;
            ExpectFailureType<TContain>::stream(ss, contain);
            ss << " was";
            if (!invertLogic) {
                ss << " not";
            }
            ss << " found in ";
            ExpectFailureType<TActual>::stream(ss, actual);;
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContainNoStringFind(const TActual& actual, const TContain& contain) {
            std::stringstream ss;
            Internal::unused(actual);
            ss << "No valid string.find() method for value ";
            ExpectFailureType<TContain>::stream(ss, contain);
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContainNoIteratorNoContains(const TActual& actual, const TContain& contain) {
            Internal::unused(actual);
            std::stringstream ss;
            ss << "Could not compare range-based iterator to ";
            ExpectFailureType<TContain>::stream(ss, contain);
            ss << ", and no usable contains method defined on object";
            return ss.str();
        }

        template <class TActual, class TContain> static std::string makeContainNotIterableNoContains(const TActual& actual, const TContain& contain) {
            Internal::unused(actual, contain);
            std::stringstream ss;
            ss << "Object is not iterable, and no usable contains method defined on object";
            return ss.str();
        }
    };
}