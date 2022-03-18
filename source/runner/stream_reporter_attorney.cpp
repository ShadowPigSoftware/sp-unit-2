#include "runner/stream_reporter_attorney.hpp"
#include "runner/output_stream.hpp"
#include "runner/reporter.hpp"

namespace SPUnit::Internal {
    OutputStream& StreamReporterAttorney::stream(Reporter& reporter) {
        return reporter.stream();
    }
}