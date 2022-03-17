#include "runner/runner.hpp"

#include "fixture/global_fixture.hpp"

namespace SPUnit {
   
    Runner::Runner(Reporter& reporter, OutputStream& outputStream):
        _reporter(&reporter),
        _outputStream(&outputStream)
    {}

    int Runner::run()
    {
        _global_spunit_fixture.run(*_reporter, *_outputStream);
        return 0;
    };
}