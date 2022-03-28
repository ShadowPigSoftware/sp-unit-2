#include "expect/make_expect.hpp"

namespace SPUnit {
    MakeExpect::MakeExpect(Scenario& scenario, uint32_t line, bool execute):
        _scenario {scenario},
        _line {line},
        _execute {execute}
    {}
}