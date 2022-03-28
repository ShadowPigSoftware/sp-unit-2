#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"

#include "scenario_delegate.hpp"
#include "scenario_status.hpp"
#include "scenario_fail_on_first_error.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario: public Runnable {
    public:
        using Flags = CommonFlags;
        using Delegate = ScenarioDelegate;
        using Status = ScenarioStatus::Status;
        using Error = ScenarioStatus::Error;
        using FailOnFirstError = ScenarioFailOnFirstError;
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const char* file, uint32_t line);
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;

        const ScenarioStatus& status() const;
        void fail(const std::string& error, uint32_t line);

        bool failOnFirstError() const;
    private:
        void run(Reporter& reporter) override;
        void runDelegate(Reporter& reporter);
        void handleUncaughtException();
    private:
        const char* const _description;
        Delegate& _delegate;
        ScenarioStatus _status;
    };
}