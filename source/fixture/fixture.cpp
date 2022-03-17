#include "fixture/fixture.hpp"
#include "scenario/scenario.hpp"
#include "runner/reporter.hpp"
#include "runner/output_stream.hpp"

namespace SPUnit {
    Fixture::Fixture():
         _parent {nullptr},
        _description {nullptr},
        _flags {},
        _file {nullptr},
        _line {0}
    {}

    Fixture::Fixture(Fixture* parent, const char* description, const char* file, uint32_t line):
        Fixture(parent, description, Flags {}, file, line)
    {}

    Fixture::Fixture(Fixture* parent, const char* description, const Flags& flags, const char* file, uint32_t line):
        _parent {parent},
        _description {description},
        _flags {flags},
        _file {file},
        _line {line}
    {
        parent->addFixture(*this);
    }

    const char* Fixture::description() const {
        return _description;
    }

    void Fixture::addScenario(const Scenario& scenario) {
        _runnables.push_back(&scenario);
    }

    void Fixture::addFixture(const Fixture& fixture) {
        _runnables.push_back(&fixture);
    }

    void Fixture::run(Reporter& reporter, OutputStream& stream) const {
        reporter.beginFixture(*this, stream);
        //before()
        for (const Runnable* runnable: _runnables) {
            //beforeEach();
            runnable->run(reporter, stream);
            //afterEach();
        }
        //after();
        reporter.endFixture(*this, stream);
    }

    void Fixture::run(const Runnable* runnable, Reporter& reporter, OutputStream& stream) {
        runnable->run(reporter, stream);
    }
}