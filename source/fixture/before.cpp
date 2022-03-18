#include "fixture/before.hpp"
#include "fixture/fixture_before_attorney.hpp"
#include "runner/stream_reporter_attorney.hpp"
#include "runner/reporter.hpp"

namespace SPUnit {    
    Before::Before(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        Before {parent, delegate, {}, file, line}
    {}

    Before::Before(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        FixtureSection {parent, delegate, flags, file, line}
    {
        Internal::FixtureBeforeAttorney::addBefore(*parent, *this);
    }

    void Before::run(Reporter& reporter) const {
        if (_flags.contains(_flags.skip)) {
            reporter.skipBefore(*this);
        }
        else
        {
            reporter.beginBefore(*this);
            _delegate.function({reporter, Internal::StreamReporterAttorney::stream(reporter)});
            reporter.endBefore(*this);
        }
    }
}
