#include "fixture/fixture_before_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureBeforeAttorney::addBefore(Fixture& fixture, Before& before) {
        fixture.addBefore(before);
    }
}