#include "expect/make_expect.hpp"

namespace SPUnit {
    MakeExpect::MakeExpect(Scenario& scenario, uint32_t line):
        _scenario {scenario},
        _line {line}
    {}
}