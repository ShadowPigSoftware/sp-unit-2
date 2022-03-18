#include "runner/null_reporter.hpp"

namespace SPUnit {    
    void NullReporter::skipFixture(const Fixture&) {}
    void NullReporter::beginFixture(const Fixture&) {}
    void NullReporter::endFixture(const Fixture&) {}
    void NullReporter::skipScenario(const Scenario&) {}
    void NullReporter::beginScenario(const Scenario&) {}
    void NullReporter::endScenario(const Scenario&) {}
    void NullReporter::skipBeforeEach(const BeforeEach&) {}
    void NullReporter::beginBeforeEach(const BeforeEach&) {}
    void NullReporter::endBeforeEach(const BeforeEach&) {}
    void NullReporter::skipAfterEach(const AfterEach&) {}
    void NullReporter::beginAfterEach(const AfterEach&) {}
    void NullReporter::endAfterEach(const AfterEach&) {}
    void NullReporter::skipBefore(const Before&) {}
    void NullReporter::beginBefore(const Before&) {}
    void NullReporter::endBefore(const Before&) {}
    void NullReporter::skipAfter(const After&) {}
    void NullReporter::beginAfter(const After&) {}
    void NullReporter::endAfter(const After&) {}
    void NullReporter::finalize() {}
}
