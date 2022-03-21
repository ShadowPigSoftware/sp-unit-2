#pragma once

#include "runner/aggregate_reporter.hpp"
#include "runner/aggregate_output_stream.hpp"

namespace SPUnit {
    class DelegateUtilities {
    public:
        AggregateReporter reporter;
        AggregateOutputStream stream;
    };
}