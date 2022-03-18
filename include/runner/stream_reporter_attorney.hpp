
#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Scenario;
    class FixtureSection;
    class Reporter;
    class OutputStream;

    namespace Internal {
        class StreamReporterAttorney {
            friend class Scenario;
            friend class FixtureSection;
        public:
            static OutputStream& stream(Reporter& reporter);
        };
    }
}