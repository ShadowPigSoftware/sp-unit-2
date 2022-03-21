#pragma once

#include "runner/aggregate_reporter.hpp"
#include "runner/aggregate_output_stream.hpp"

#include "expect/make_expect.hpp"

namespace SPUnit {
    class ScenarioDelegateUtilities {
    public:
        AggregateReporter reporter;
        AggregateOutputStream stream;
        void fail(const char* message = "", uint32_t line = 0);
        MakeExpect make_expect(uint32_t line);
    private:
        friend class ScenarioDelegate;
        Scenario* _scenario;
    };
}