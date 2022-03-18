#include "fixture/fixture.hpp"
#include "fixture/before_each.hpp"
#include "fixture/after_each.hpp"
#include "fixture/before.hpp"
#include "fixture/after.hpp"
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

    void Fixture::addBeforeEach(const BeforeEach& beforeEach) {
        _beforeEachs.push_back(&beforeEach);
    }
    
    void Fixture::addAfterEach(const AfterEach& afterEach) {
        _afterEachs.push_back(&afterEach);
    }

    void Fixture::addBefore(const Before& before) {
        _befores.push_back(&before);
    }

    void Fixture::addAfter(const After& after) {
        _afters.push_back(&after);
    }

    void Fixture::run(Reporter& reporter) const {
        reporter.beginFixture(*this);
        for (const Runnable* before: _befores) {
            before->run(reporter);
        }
        for (const Runnable* runnable: _runnables) {
            for (const Runnable* beforeEach: _beforeEachs) {
                beforeEach->run(reporter);
            }
            runnable->run(reporter);
            for (const Runnable* afterEach: _afterEachs) {
                afterEach->run(reporter);
            }
        }
        for (const Runnable* after: _afters) {
            after->run(reporter);
        }
        reporter.endFixture(*this);
    }

    void Fixture::run(const Runnable* runnable, Reporter& reporter) {
        runnable->run(reporter);
    }
}