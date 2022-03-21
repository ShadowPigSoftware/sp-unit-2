#include "runner/spec_reporter.hpp"
#include "runner/output_stream.hpp"
#include "fixture/fixture.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {    
    SpecReporter::SpecReporter(const char* tickSymbol, const char* crossSymbol):
        _tickSymbol {tickSymbol},
        _crossSymbol {crossSymbol},
        _indent {0},
        _index {0},
        _scenarioCount {0},
        _failures {}
    {}

    void SpecReporter::beginFixture(const Fixture& fixture) {
        printIndent();
        stream() << fixture.description() << stream().endl;
        ++_indent;
    }
        
    void SpecReporter::endFixture(const Fixture& fixture) {
        Internal::unused(fixture);
        --_indent;
    }
    
    void SpecReporter::endScenario(const Scenario& scenario) {
        printIndent();
        ++_scenarioCount;
        SPUnit::OutputStream& stream = this->stream();
        if (scenario.status() == Scenario::Status::Success) {
            stream << stream.green << _tickSymbol << " " << stream.reset;
        }
        else {
            _failures.push_back(&scenario);
            stream << stream.red << _index << ") " << stream.reset;
            ++_index;
        }
        stream << scenario.description() << stream.endl;
    }

    void SpecReporter::finalize() {
        if (_failures.empty()) {
            finalizeSuccess();
        }
        else {
            finalizeFailure();
        }
    }

    void SpecReporter::finalizeSuccess() {
        SPUnit::OutputStream& stream = this->stream();
        stream << stream.endl << stream.green << _tickSymbol << " " << _scenarioCount << " tests completed" << stream.reset << stream.endl << stream.endl;
    }
        
    void SpecReporter::finalizeFailure() {
        SPUnit::OutputStream& stream = this->stream();
        stream << stream.endl << stream.red << _crossSymbol << " " << _failures.size() << " of " << _scenarioCount << " tests failed";
        stream << stream.reset << ":" << stream.endl << stream.endl;
        uint32_t index = 0;
        for (const Scenario* scenario : _failures) {
            stream << stream.white << index << ") " << scenario->description() << ": ";
            stream << stream.red << scenario->status().error().c_str() << stream.endl;
            stream << stream.reset << "  at " << scenario->status().file() << ":" << scenario->status().line() << stream.endl << stream.endl;
            ++index;

        }
    }

    void SpecReporter::printIndent()
    {
        for (uint32_t i = 0; i < _indent; ++i) {
            stream() << "  ";
        }
    }
}
