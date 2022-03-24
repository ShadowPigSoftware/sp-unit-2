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

        struct Error {
            std::string error;
            const char* file;
            uint32_t line;
        };

        using ErrorList = std::list<Error>;
        
        bool operator == (Status status) const;

        void addFailure(const Error& error);

        const ErrorList& errors() const;
    private:
        ErrorList _errors;
    };
}