#include "runner/runner_reporter_attorney.hpp"
#include "runner/reporter.hpp"

namespace SPUnit::Internal {
    void RunnerReporterAttorney::setOutputStream(Reporter& reporter, OutputStream& stream) {
        reporter.setOutputStream(stream);
    }
}