#pragma once

#include "runner/aggregate_reporter.hpp"
#include "runner/aggregate_output_stream.hpp"

namespace SPUnit {
    class ScenarioDelegateUtilities {
    public:
        AggregateReporter reporter;
        AggregateOutputStream stream;
        void fail(const char* message = "", uint32_t line = 0);
    private:
        friend class ScenarioDelegate;
        Scenario* _scenario;
    };
}