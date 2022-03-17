#pragma once

#include "spunit_core.hpp"
namespace SPUnit {
    class Fixture;
    class Scenario;
    class OutputStream;
    
    class Reporter {
    public:
        virtual ~Reporter() = default;
        virtual void beginFixture(const Fixture& fixture, OutputStream& stream) = 0;
        virtual void endFixture(const Fixture& fixture, OutputStream& stream) = 0;
        virtual void beginScenario(const Scenario& scenario, OutputStream& stream) = 0;
        virtual void endScenario(const Scenario& scenario, OutputStream& stream) = 0;
    };
}
