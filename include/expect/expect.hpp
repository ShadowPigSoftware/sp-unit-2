#pragma once

#include "expect_to.hpp"
namespace SPUnit {
    class Scenario;

    template <class T> class Expect {
    public:
        Expect(Scenario& scenario, uint32_t line, typename ExpectType<T>::ParameterType actual):
            to {scenario, line, actual}
        {}

        ExpectTo<T> to;
    };
}