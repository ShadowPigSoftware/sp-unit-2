#include "runner/spec_reporter.hpp"
#include "runner/output_stream.hpp"
#include "fixture/fixture.hpp"
#include "scenario/scenario.hpp"

namespace SPUnit {    
    void SpecReporter::beginFixture(const Fixture& fixture) {
        printIndent();
        stream() << fixture.description() << stream().endl;
        ++indent;
    }
        
    void SpecReporter::endFixture(const Fixture& fixture) {
        Internal::unused(fixture);
        --indent;
    }
    
    void SpecReporter::endScenario(const Scenario& scenario) {
        stream() << scenario.description() << stream().endl;
    }

    void SpecReporter::printIndent()
    {
        for (uint32_t i = 0; i < indent; ++i) {
            stream() << "  ";
        }
    }
}
