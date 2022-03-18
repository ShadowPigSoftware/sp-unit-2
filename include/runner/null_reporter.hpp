#pragma once

#include "reporter.hpp"

namespace SPUnit {    
    class NullReporter: public Reporter {
    public:
        void beginFixture(const Fixture& fixture) override;
        void endFixture(const Fixture& fixture) override;
        void beginScenario(const Scenario& scenario) override;
        void endScenario(const Scenario& scenario) override;
        void beginBeforeEach(const BeforeEach& beforeEach) override;
        void endBeforeEach(const BeforeEach& beforeEach) override;
        void beginAfterEach(const AfterEach& afterEach) override;
        void endAfterEach(const AfterEach& afterEach) override;
        void beginBefore(const Before& before) override;
        void endBefore(const Before& before) override;
        void beginAfter(const After& after) override;
        void endAfter(const After& after) override;
        void finalize() override;
    };
}
