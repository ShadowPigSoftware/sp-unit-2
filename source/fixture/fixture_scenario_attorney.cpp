#include "fixture/fixture_scenario_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureScenarioAttorney::addScenario(Fixture& fixture, Scenario& scenario) {
        fixture.addScenario(scenario);
    }
}