#pragma once

#include "spunit_core.hpp"
#include "reporter.hpp"
#include "output_stream.hpp"

namespace SPUnit {
    class Runner {
    public:
        Runner(Reporter& reporter, OutputStream& outputStream);
        int run();
    private:
        Reporter* _reporter;
    };
}
