
#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Runner;
    class Reporter;
    class OutputStream;

    namespace Internal {
        class RunnerReporterAttorney {
            friend class Runner;
        public:
            static void setOutputStream(Reporter& reporter, OutputStream& stream);
        };
    }
}