#include "fixture/fixture_after_each_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureAfterEachAttorney::addAfterEach(Fixture& fixture, const AfterEach& afterEach) {
        fixture.addAfterEach(afterEach);
    }
}