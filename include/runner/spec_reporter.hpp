#pragma once

#include "null_reporter.hpp"

namespace SPUnit {    
    class SpecReporter: public NullReporter {
    public:
        static constexpr const char* defaultTickSymbol = "\u2713";
        static constexpr const char* defaultCrossSymbol = "\u2716";
        SpecReporter(const char* tickSymbol = defaultTickSymbol, const char* crossSymbol = defaultCrossSymbol);
        void beginFixture(const Fixture& fixture) override;
        void endFixture(const Fixture& fixture) override;
        void endScenario(const Scenario& scenario) override;
        void finalize() override;
    private:
        void finalizeSuccess();
        void finalizeFailure();
        void printIndent();
        const char* _tickSymbol;
        const char* _crossSymbol;
        uint32_t _indent;
        uint32_t _index;
        uint32_t _scenarioCount;
        using ScenarioList = std::list<const Scenario*>;
        ScenarioList _failures;
    };
}
