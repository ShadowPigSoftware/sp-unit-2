#pragma once

#include "spunit_core.hpp"
#include "runner_reporter_attorney.hpp"
#include "stream_reporter_attorney.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario;
    class BeforeEach;
    class AfterEach;
    class Before;
    class After;
    class OutputStream;
    
    class Reporter {
    public:
        Reporter();
        virtual ~Reporter() = default;
        virtual void skipFixture(const Fixture& fixture) = 0;
        virtual void beginFixture(const Fixture& fixture) = 0;
        virtual void endFixture(const Fixture& fixture) = 0;
        virtual void skipScenario(const Scenario& scenario) = 0;
        virtual void beginScenario(const Scenario& scenario) = 0;
        virtual void endScenario(const Scenario& scenario) = 0;
        virtual void skipBeforeEach(const BeforeEach& beforeEach) = 0;
        virtual void beginBeforeEach(const BeforeEach& beforeEach) = 0;
        virtual void endBeforeEach(const BeforeEach& beforeEach) = 0;
        virtual void skipAfterEach(const AfterEach& afterEach) = 0;
        virtual void beginAfterEach(const AfterEach& afterEach) = 0;
        virtual void endAfterEach(const AfterEach& afterEach) = 0;
        virtual void skipBefore(const Before& before) = 0;
        virtual void beginBefore(const Before& before) = 0;
        virtual void endBefore(const Before& before) = 0;
        virtual void skipAfter(const After& after) = 0;
        virtual void beginAfter(const After& after) = 0;
        virtual void endAfter(const After& after) = 0;

        virtual void finalize() = 0;
    protected:
        friend class Internal::StreamReporterAttorney;
        OutputStream& stream();
    private:
        friend class Internal::RunnerReporterAttorney;
        void setOutputStream(OutputStream& stream);
        OutputStream* _stream;
    };
}
