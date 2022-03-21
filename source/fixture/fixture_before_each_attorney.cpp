#include "fixture/fixture_before_each_attorney.hpp"
#include "fixture/fixture.hpp"

namespace SPUnit::Internal {
    void FixtureBeforeEachAttorney::addBeforeEach(Fixture& fixture, BeforeEach& beforeEach) {
        fixture.addBeforeEach(beforeEach);
    }
}