#include "fixture/before_each.hpp"
#include "fixture/fixture_before_each_attorney.hpp"
#include "runner/stream_reporter_attorney.hpp"
#include "runner/reporter.hpp"

namespace SPUnit {    
    BeforeEach::BeforeEach(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        BeforeEach {parent, delegate, {}, file, line}
    {}

    BeforeEach::BeforeEach(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        FixtureSection {parent, delegate, flags, file, line}
    {
        Internal::FixtureBeforeEachAttorney::addBeforeEach(*parent, *this);
    }

    void BeforeEach::run(Reporter& reporter) const {
        if (_flags.contains(_flags.skip)) {
            reporter.skipBeforeEach(*this);
        }
        else
        {
            reporter.beginBeforeEach(*this);
            _delegate.function({reporter, Internal::StreamReporterAttorney::stream(reporter)});
            reporter.endBeforeEach(*this);
        }
    }
}
