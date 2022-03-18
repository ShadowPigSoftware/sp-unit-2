#include "runner/runner.hpp"
#include "runner/runner_reporter_attorney.hpp"
#include "fixture/global_fixture.hpp"

namespace SPUnit {
   
    Runner::Runner(Reporter& reporter, OutputStream& outputStream):
        _reporter(&reporter),
        _outputStream(&outputStream)
    {
        Internal::RunnerReporterAttorney::setOutputStream(reporter, outputStream);
    }

    int Runner::run()
    {
        _global_spunit_fixture.run(*_reporter);
        return 0;
    };

    void Runner::setReporter(Reporter& reporter)
    {
        _reporter = &reporter;
        Internal::RunnerReporterAttorney::setOutputStream(*_reporter, *_outputStream);
    }

    void Runner::setOutputStream(OutputStream& outputStream)
    {
        _outputStream = &outputStream;
        Internal::RunnerReporterAttorney::setOutputStream(*_reporter, *_outputStream);
    }
}