#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class BeforeEach;

    namespace Internal {
        class FixtureBeforeEachAttorney {
            friend class BeforeEach;
            friend class Fixture;
        public:
            static void addBeforeEach(Fixture& fixture, BeforeEach& beforeEach);
        };
    }
}