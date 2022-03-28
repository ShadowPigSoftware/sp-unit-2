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
    
    void Scenario::run(Reporter& reporter) {
        if (_flags.contains(_flags.skip)) {
            reporter.skipScenario(*this);
        } else {
            reporter.beginScenario(*this);
            runDelegate(reporter);
            
            reporter.endScenario(*this);
        }
    }

    void Scenario::runDelegate(Reporter& reporter) {
        try {
            _delegate.function(*this, reporter, Internal::StreamReporterAttorney::stream(reporter));
        }
        catch (const FailOnFirstError&)
        {
            //do nothing.
        }
        catch (...) {
            handleUncaughtException();
        }
    }

    void Scenario::handleUncaughtException() {
        if (!(failOnFirstError() && _status.errors().size() == 1)) {
            _status.addFailure(ScenarioStatus::Error {"Uncaught Exception", _file, 0});
        }
    }

    const char* Scenario::description() const {
        return _description;
    }

    const ScenarioStatus& Scenario::status() const {
        return _status;
    }

    void Scenario::fail(const std::string& error, uint32_t line) {
        //TODO failonFirstError Here
        if (failOnFirstError() && _status.errors().size() == 1) {
            throw FailOnFirstError();
        } else {
            _status.addFailure(ScenarioStatus::Error {error, _file, line});
        }
    }

    bool Scenario::failOnFirstError() const {
        return _flags.contains(_flags.failOnFirstError);
    }
}