#include "scenario/scenario_delegate_utilities.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {
    void ScenarioDelegateUtilities::fail(const char* message, uint32_t line){
        _scenario->fail(message, line);
    }
}