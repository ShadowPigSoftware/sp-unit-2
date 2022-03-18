#include "runner/null_reporter.hpp"

namespace SPUnit {    
    void NullReporter::beginFixture(const Fixture&) {}
    void NullReporter::endFixture(const Fixture&) {}
    void NullReporter::beginScenario(const Scenario&) {}
    void NullReporter::endScenario(const Scenario&) {}
    void NullReporter::beginBeforeEach(const BeforeEach&) {}
    void NullReporter::endBeforeEach(const BeforeEach&) {}
    void NullReporter::beginAfterEach(const AfterEach&) {}
    void NullReporter::endAfterEach(const AfterEach&) {}
    void NullReporter::beginBefore(const Before&) {}
    void NullReporter::endBefore(const Before&) {}
    void NullReporter::beginAfter(const After&) {}
    void NullReporter::endAfter(const After&) {}
    void NullReporter::finalize() {}
}
