#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "common/delegate.hpp"

#include "scenario_status.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario: public Runnable {
    public:
        using Flags = CommonFlags;
        using Delegate = ::SPUnit::Delegate;
        using Status = ScenarioStatus::Status;
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const char* file, uint32_t line);
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;

        const ScenarioStatus& status() const;
    private:
        void run(Reporter& reporter) const override;
    private:
        const char* const _description;
        Delegate& _delegate;
        ScenarioStatus _status;
    };
}