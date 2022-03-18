#include "fixture/fixture_scenario_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureScenarioAttorney::addScenario(Fixture& fixture, const Scenario& scenario) {
        fixture.addScenario(scenario);
    }
}