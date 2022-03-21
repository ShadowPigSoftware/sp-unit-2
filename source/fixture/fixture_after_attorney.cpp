#include "fixture/fixture_after_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureAfterAttorney::addAfter(Fixture& fixture, After& after) {
        fixture.addAfter(after);
    }
}