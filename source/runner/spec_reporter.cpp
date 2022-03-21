#include "runner/spec_reporter.hpp"
#include "runner/output_stream.hpp"
#include "fixture/fixture.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {    
    SpecReporter::SpecReporter(const char* tickSymbol, const char* crossSymbol):
        _tickSymbol {tickSymbol},
        _crossSymbol {crossSymbol},
        _indent {0},
        _index {0}
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
        SPUnit::OutputStream& stream = this->stream();
        if (scenario.status() == Scenario::Status::Success) {
            stream << stream.green << _tickSymbol << " " << stream.white;
        }
        else {
            stream << stream.red << _index << ") " << stream.white;
            ++_index;
        }
        stream << scenario.description() << stream.endl;
    }

    void SpecReporter::printIndent()
    {
        for (uint32_t i = 0; i < _indent; ++i) {
            stream() << "  ";
        }
    }
}
