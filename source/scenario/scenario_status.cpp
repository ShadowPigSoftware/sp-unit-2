#include "scenario/scenario_status.hpp"

namespace SPUnit {        
    bool ScenarioStatus::operator == (Status status) const {
        bool hasErrors = (_errors.size() == 0);
        if (status == Status::Success) {
            return hasErrors;
        }
        else
        {
            return !hasErrors;
        }
    }
    
    void ScenarioStatus::addFailure(const Error& error) {
        _errors.push_back(error);
    }

    const ScenarioStatus::ErrorList& ScenarioStatus::errors() const {
        return _errors;
    }
}