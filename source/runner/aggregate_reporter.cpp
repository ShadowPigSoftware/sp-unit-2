#include "runner/aggregate_reporter.hpp"
#include "runner/null_reporter.hpp"

namespace SPUnit {   
    namespace {
        NullReporter nullReporter;
    }

    AggregateReporter::AggregateReporter():
        _reporter {&nullReporter}
    {}

    AggregateReporter::AggregateReporter(Reporter& reporter):  
        _reporter {&reporter}
    {}

    AggregateReporter& AggregateReporter::operator=(Reporter& reporter) {
        _reporter = &reporter;
        return *this;
    }

    void AggregateReporter::skipFixture(const Fixture& fixture) {_reporter->skipFixture(fixture);}
    void AggregateReporter::beginFixture(const Fixture& fixture) {_reporter->skipFixture(fixture);}
    void AggregateReporter::endFixture(const Fixture& fixture) {_reporter->skipFixture(fixture);}
    void AggregateReporter::skipScenario(const Scenario& scenario) {_reporter->skipScenario(scenario);}
    void AggregateReporter::beginScenario(const Scenario& scenario) {_reporter->beginScenario(scenario);}
    void AggregateReporter::endScenario(const Scenario& scenario) {_reporter->endScenario(scenario);}
    void AggregateReporter::skipBeforeEach(const BeforeEach& beforeEach) {_reporter->skipBeforeEach(beforeEach);}
    void AggregateReporter::beginBeforeEach(const BeforeEach& beforeEach) {_reporter->beginBeforeEach(beforeEach);}
    void AggregateReporter::endBeforeEach(const BeforeEach& beforeEach) {_reporter->endBeforeEach(beforeEach);}
    void AggregateReporter::skipAfterEach(const AfterEach& afterEach) {_reporter->skipAfterEach(afterEach);}
    void AggregateReporter::beginAfterEach(const AfterEach& afterEach) {_reporter->beginAfterEach(afterEach);}
    void AggregateReporter::endAfterEach(const AfterEach& afterEach) {_reporter->endAfterEach(afterEach);}
    void AggregateReporter::skipBefore(const Before& before) {_reporter->skipBefore(before);}
    void AggregateReporter::beginBefore(const Before& before) {_reporter->beginBefore(before);}
    void AggregateReporter::endBefore(const Before& before) {_reporter->endBefore(before);}
    void AggregateReporter::skipAfter(const After& after) {_reporter->skipAfter(after);}
    void AggregateReporter::beginAfter(const After& after) {_reporter->beginAfter(after);}
    void AggregateReporter::endAfter(const After& after) {_reporter->endAfter(after);}
    void AggregateReporter::finalize() {_reporter->finalize();}
}
