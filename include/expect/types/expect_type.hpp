#pragma once

#include "spunit_core.hpp"

#include <sstream>

namespace SPUnit {
    template <class T> class ExpectType {
    public:
        using Type = T;
        using ParameterType = typename std::conditional<std::is_scalar<T>::value, T, const T&>::type;
        using StorageType = ParameterType;
    };
}