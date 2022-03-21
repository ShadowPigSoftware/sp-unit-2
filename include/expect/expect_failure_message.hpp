#pragma once

#include "spunit_core.hpp"
#include "expect_scenario.hpp"
#include "expect_failure_message.hpp"

#include <sstream>

namespace SPUnit {
    class Scenario;

    template <class T> class ExpectFailureType {
    public:
        static void make(std::stringstream& ss, const T& value) {
            ss << value;
        }
    };

    template <> class ExpectFailureType<const char*> {
    public:
        static void make(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };

    template <int L> class ExpectFailureType<char[L]> {
    public:
        static void make(std::stringstream& ss, const char* value) {
            ss << "\"" << value << "\"";
        }
    };

    template <> class ExpectFailureType<char> {
    public:
        static void make(std::stringstream& ss, char value) {
            ss << "\'" << value << "\'(0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value) << ")";
        }
    };

    template <> class ExpectFailureType<uint8_t> {
    public:
        static void make(std::stringstream& ss, uint8_t value) {
            ss << static_cast<int>(value);
        }
    };

    class ExpectFailureMessage {
    public:
        template <class T, class U> static std::string make(const T& actual, const U& expected) {
            std::stringstream ss;
            ss << "Expected ";
            ExpectFailureType<T>::make(ss, actual);
            ss << " to equal ";
            ExpectFailureType<U>::make(ss, expected);
            return ss.str();
        }
    };
}