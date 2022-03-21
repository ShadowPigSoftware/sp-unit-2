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
        Runnable {parent, flags, file, line},
        _description {description},
        _delegate {delegate},
        _status {}
    {
        Internal::FixtureScenarioAttorney::addScenario(*parent, *this);
    }
    
    void Scenario::run(Reporter& reporter)
    {
        if (_flags.contains(_flags.skip)) {
            reporter.skipScenario(*this);
        }
        else
        {
            reporter.beginScenario(*this);
            _delegate.function(*this, reporter, Internal::StreamReporterAttorney::stream(reporter));
            reporter.endScenario(*this);
        }
    }

    const char* Scenario::description() const {
        return _description;
    }

    const ScenarioStatus& Scenario::status() const {
        return _status;
    }

    void Scenario::fail(const std::string& error, uint32_t line) {
        _status = ScenarioStatus {error, _file, line};
    }
}