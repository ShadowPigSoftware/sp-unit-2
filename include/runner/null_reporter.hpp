#pragma once

#include "reporter.hpp"

namespace SPUnit {    
    class NullReporter: public Reporter {
    public:
        void skipFixture(const Fixture& fixture) override;
        void beginFixture(const Fixture& fixture) override;
        void endFixture(const Fixture& fixture) override;
        void skipScenario(const Scenario& scenario) override;
        void beginScenario(const Scenario& scenario) override;
        void endScenario(const Scenario& scenario) override;
        void skipBeforeEach(const BeforeEach& beforeEach) override;
        void beginBeforeEach(const BeforeEach& beforeEach) override;
        void endBeforeEach(const BeforeEach& beforeEach) override;
        void skipAfterEach(const AfterEach& afterEach) override;
        void beginAfterEach(const AfterEach& afterEach) override;
        void endAfterEach(const AfterEach& afterEach) override;
        void skipBefore(const Before& before) override;
        void beginBefore(const Before& before) override;
        void endBefore(const Before& before) override;
        void skipAfter(const After& after) override;
        void beginAfter(const After& after) override;
        void endAfter(const After& after) override;
        void finalize() override;
    };
}
