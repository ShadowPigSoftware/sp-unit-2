#include "fixture/fixture_section.hpp"

namespace SPUnit {    
    FixtureSection::FixtureSection(Fixture* parent, Delegate& delegate, const char* file, uint32_t line):
        FixtureSection {parent, delegate, {}, file, line}
    {}

    FixtureSection::FixtureSection(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line):
        _parent {parent},
        _delegate {delegate},
        _flags {flags},
        _file {file},
        _line {line}
    {}
}
