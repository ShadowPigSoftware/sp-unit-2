#include "fixture/after_each.hpp"
#include "fixture/fixture_after_each_attorney.hpp"
#include "runner/stream_reporter_attorney.hpp"
#include "runner/reporter.hpp"

namespace SPUnit {    
    AfterEach::AfterEach(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        AfterEach {parent, delegate, {}, file, line}
    {}

    AfterEach::AfterEach(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        FixtureSection {parent, delegate, flags, file, line}
    {
        Internal::FixtureAfterEachAttorney::addAfterEach(*parent, *this);
    }

    void AfterEach::run(Reporter& reporter) {
        if (_flags.contains(_flags.skip)) {
            reporter.skipAfterEach(*this);
        }
        else
        {
            reporter.beginAfterEach(*this);
            _delegate.function(reporter, Internal::StreamReporterAttorney::stream(reporter));
            reporter.endAfterEach(*this);
        }
    }
}
