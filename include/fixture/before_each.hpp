#pragma once

#include "fixture_section.hpp"

namespace SPUnit {
    class BeforeEach: public FixtureSection {
    public:
        BeforeEach(Fixture* parent, Delegate& delegate, const char* file, uint32_t line);
        BeforeEach(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);
    private:
        void run(Reporter& reporter) const override;
    };
}
