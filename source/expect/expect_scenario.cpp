#include "expect/expect_scenario.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {
    void ExpectScenario::fail(Scenario& scenario, const std::string& error, uint32_t line) {
        scenario.fail(error, line);
    }
}