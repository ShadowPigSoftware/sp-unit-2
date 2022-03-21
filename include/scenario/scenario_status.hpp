#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class ScenarioStatus {
    public:
        enum class Status {
            Success,
            Failure
        };

        ScenarioStatus();
        ScenarioStatus(const std::string& error, const char* file, uint32_t line);
        ScenarioStatus(const ScenarioStatus& status);

        ScenarioStatus& operator=(const ScenarioStatus& status);
        
        bool operator == (Status status) const;
        const std::string& error() const;
        const char* file() const;
        uint32_t line() const;
    private:
        Status _status;
        std::string _error;
        const char* _file;
        uint32_t _line;
    };
}