#include "scenario/scenario.hpp"
#include "fixture/fixture_scenario_attorney.hpp"
#include "runner/reporter.hpp"
#include "runner/output_stream.hpp"
#include "runner/stream_reporter_attorney.hpp"

namespace SPUnit {
    Scenario::Scenario(Fixture* parent, const char* description, Delegate& delegate, const char* file, uint32_t line): 
        Scenario {parent, description, delegate, Flags {}, file, line}
    {}
    
    Scenario::Scenario(Fixture* parent, const char* description, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        _parent {parent},
        _description {description},
        _delegate {delegate},
        _flags {flags},
        _file {file},
        _line {line}
    {
        Internal::FixtureScenarioAttorney::addScenario(*parent, *this);
    }
    
    void Scenario::run(Reporter& reporter) const
    {
        reporter.beginScenario(*this);
        _delegate.function({reporter, Internal::StreamReporterAttorney::stream(reporter)});
        reporter.endScenario(*this);
    }

    const char* Scenario::description() const {
        return _description;
    }
}