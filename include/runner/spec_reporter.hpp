#pragma once

#include "reporter.hpp"

namespace SPUnit {    
    class SpecReporter: public Reporter {
    public:
        void beginFixture(const Fixture& fixture, OutputStream& stream) override;
        void endFixture(const Fixture& fixture, OutputStream& stream) override;
        void beginScenario(const Scenario& scenario, OutputStream& stream) override;
        void endScenario(const Scenario& scenario, OutputStream& stream) override;
    private:
        void printIndent(OutputStream& stream);
        uint32_t indent = 0;
    };
}
