#pragma once

#include "spunit_core.hpp"
#include "reporter.hpp"
#include "output_stream.hpp"

namespace SPUnit {
    class Runner {
    public:
        Runner(Reporter& reporter, OutputStream& outputStream);
        int run();

        void setReporter(Reporter& reporter);
        void setOutputStream(OutputStream& outputStream);
    private:
        Reporter* _reporter;
        OutputStream* _outputStream;
    };
}
