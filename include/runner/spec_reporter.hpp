#pragma once

#include "null_reporter.hpp"

namespace SPUnit {    
    class SpecReporter: public NullReporter {
    public:
        void beginFixture(const Fixture& fixture) override;
        void endFixture(const Fixture& fixture) override;
        void endScenario(const Scenario& scenario) override;
    private:
        void printIndent();
        uint32_t indent = 0;
    };
}
