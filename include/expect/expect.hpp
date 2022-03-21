#pragma once

#include "expect_to.hpp"
#include "expect_type.hpp"
namespace SPUnit {
    class Scenario;

    template <class T> class Expect {
    public:
        using Type = typename ExpectType<T>::Type;
        Expect(Scenario& scenario, uint32_t line, Type actual):
            to {scenario, line, actual}
        {}

        ExpectTo<Type> to;
    };
}