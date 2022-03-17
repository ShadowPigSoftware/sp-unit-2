#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario;

    namespace Internal {
        class FixtureScenarioAttorney {
            friend class Scenario;
            friend class Fixture;
        public:
            static void addScenario(Fixture& fixture, const Scenario& scenario);
        };
    }
}