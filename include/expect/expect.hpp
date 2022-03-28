#pragma once

#include "expect_to.hpp"

namespace SPUnit {
    class Scenario;

    template <class T> class Expect {
    public:
        Expect(Scenario& scenario, uint32_t line, bool execute, typename ExpectType<T>::ParameterType actual):
            to {scenario, line, execute, actual},
            notTo {scenario, line, execute, actual, true}
        {}

        ExpectTo<T> to;
        ExpectTo<T> notTo;
    };
}