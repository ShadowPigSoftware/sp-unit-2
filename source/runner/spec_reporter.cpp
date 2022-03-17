#include "runner/spec_reporter.hpp"
#include "runner/output_stream.hpp"
#include "fixture/fixture.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {    
    void SpecReporter::beginFixture(const Fixture& fixture, OutputStream& stream) {
        printIndent(stream);
        stream << fixture.description() << stream.endl;
        ++indent;
    }
        
    void SpecReporter::endFixture(const Fixture& fixture, OutputStream& stream) {
        Internal::unused(fixture, stream);
        --indent;
    }

    void SpecReporter::beginScenario(const Scenario& scenario, OutputStream& stream) {
        Internal::unused(scenario, stream);
    }
    
    void SpecReporter::endScenario(const Scenario& scenario, OutputStream& stream) {
        stream << scenario.description() << stream.endl;
    }

    void SpecReporter::printIndent(OutputStream& stream)
    {
        for (uint32_t i = 0; i < indent; ++i) {
            stream << "  ";
        }
    }
}
