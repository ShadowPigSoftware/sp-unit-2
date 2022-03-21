#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class After;

    namespace Internal {
        class FixtureAfterAttorney {
            friend class After;
            friend class Fixture;
        public:
            static void addAfter(Fixture& fixture, After& after);
        };
    }
}