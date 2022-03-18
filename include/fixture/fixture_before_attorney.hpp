#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Fixture;
    class Before;

    namespace Internal {
        class FixtureBeforeAttorney {
            friend class Before;
            friend class Fixture;
        public:
            static void addBefore(Fixture& fixture, const Before& before);
        };
    }
}