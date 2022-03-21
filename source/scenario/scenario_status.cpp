#include "scenario/scenario_status.hpp"

namespace SPUnit {
    bool ScenarioStatus::operator == (Status status) const {
        return _status == status;
    }
}