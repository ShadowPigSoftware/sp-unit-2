#include "fixture/after.hpp"
#include "fixture/fixture_after_attorney.hpp"
#include "runner/stream_reporter_attorney.hpp"
#include "runner/reporter.hpp"

namespace SPUnit {    
    After::After(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        After {parent, delegate, {}, file, line}
    {}

    After::After(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        FixtureSection {parent, delegate, flags, file, line}
    {
        Internal::FixtureAfterAttorney::addAfter(*parent, *this);
    }

    void After::run(Reporter& reporter) {
        if (_flags.contains(_flags.skip)) {
            reporter.skipAfter(*this);
        }
        else
        {
            reporter.beginAfter(*this);
            _delegate.function(reporter, Internal::StreamReporterAttorney::stream(reporter));
            reporter.endAfter(*this);
        }
    }
}
