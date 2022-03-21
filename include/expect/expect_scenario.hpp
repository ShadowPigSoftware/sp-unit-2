#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Scenario;

    //Expect cannot know about scenario without cyclic dependecy, this breaks that cycle
    class ExpectScenario {
    public:
        static void fail(Scenario& scenario, const std::string& error, uint32_t line);
    };
}