#include "fixture/fixture_section.hpp"

namespace SPUnit {    
    FixtureSection::FixtureSection(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        FixtureSection {parent, delegate, {}, file, line}
    {}

    FixtureSection::FixtureSection(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        Runnable {parent, flags, file, line},
        _delegate {delegate}
    {}
}
