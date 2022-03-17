#include "scenario/scenario.hpp"
#include "fixture/fixture_scenario_attorney.hpp"
#include "runner/reporter.hpp"
#include "runner/output_stream.hpp"

namespace SPUnit {
    Scenario::Scenario(Fixture* parent, const char* description, Function function, const char* file, uint32_t line): 
        Scenario {parent, description, function, Flags {}, file, line}
    {}
    
    Scenario::Scenario(Fixture* parent, const char* description, Function function, const Flags& flags, const char* file, uint32_t line):
        _parent {parent},
        _description {description},
        _function {function},
        _flags {flags},
        _file {file},
        _line {line}
    {
        Internal::FixtureScenarioAttorney::addScenario(*parent, *this);
    }
    
    void Scenario::run(Reporter& reporter, OutputStream& stream) const
    {
        reporter.beginScenario(*this, stream);
        _function();
        reporter.endScenario(*this, stream);
    }

    const char* Scenario::description() const {
        return _description;
    }
}