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

        bool operator == (Status status) const;
    private:
        Status _status = Status::Success;
    };
}