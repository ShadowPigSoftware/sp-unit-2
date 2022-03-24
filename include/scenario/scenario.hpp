#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"

#include "scenario_delegate.hpp"
#include "scenario_status.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario: public Runnable {
    public:
        using Flags = CommonFlags;
        using Delegate = ScenarioDelegate;
        using Status = ScenarioStatus::Status;
        using Error = ScenarioStatus::Error;
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const char* file, uint32_t line);
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;

        const ScenarioStatus& status() const;
        void fail(const std::string& error, uint32_t line);
    private:
        void run(Reporter& reporter) override;
    private:
        const char* const _description;
        Delegate& _delegate;
        ScenarioStatus _status;
    };
}