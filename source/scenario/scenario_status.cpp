#include "scenario/scenario_status.hpp"

namespace SPUnit {
    
    ScenarioStatus::ScenarioStatus():
        _status {Status::Success},
        _error {},
        _file {nullptr},
        _line {0}
    {}

    ScenarioStatus::ScenarioStatus(const std::string& error, const char* file, uint32_t line):
        _status {Status::Failure},
        _error {error},
        _file {file},
        _line {line}
    {}

    ScenarioStatus::ScenarioStatus(const ScenarioStatus& status):
        _status {status._status},
        _error {status._error},
        _file {status._file},
        _line {status._line}
    {}

    ScenarioStatus& ScenarioStatus::operator=(const ScenarioStatus& status) {
         _status = status._status;
        _error = status._error;
        _file = status._file;
        _line = status._line;
        return *this;
    }
        
    bool ScenarioStatus::operator == (Status status) const {
        return _status == status;
    }
    
    const std::string& ScenarioStatus::error() const
    {
        return _error;
    }
    
    const char* ScenarioStatus::file() const
    {
        return _file;
    }
    
    uint32_t ScenarioStatus::line() const
    {
        return _line;
    }
}