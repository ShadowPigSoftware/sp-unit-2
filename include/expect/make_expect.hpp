#pragma once

#include "expect.hpp"
#include "types/expect_type.hpp"

namespace SPUnit {
    class Scenario;

    class MakeExpect {
    public:
        MakeExpect(Scenario& scenario, uint32_t line);

        template <class T> Expect<T> run(T&& actual) {
            return Expect<T> {_scenario, _line, actual};
        }
    private:
        Scenario& _scenario;
        uint32_t _line;
    };
}