#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class AfterEach;

    namespace Internal {
        class FixtureAfterEachAttorney {
            friend class AfterEach;
            friend class Fixture;
        public:
            static void addAfterEach(Fixture& fixture, AfterEach& afterEach);
        };
    }
}