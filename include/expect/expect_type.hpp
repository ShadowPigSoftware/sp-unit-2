#pragma once

#include "expect_to.hpp"

namespace SPUnit {
    class Scenario;

    template <class T, class Enabler = void> class ExpectType {
    public:
        using Type = const T&;
    };

    template <class T> class ExpectType<T, typename std::enable_if_t<std::is_scalar<T>::value>> {
    public:
        using Type = T;
    };

}