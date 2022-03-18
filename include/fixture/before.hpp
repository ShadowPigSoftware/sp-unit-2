#pragma once

#include "fixture_section.hpp"

namespace SPUnit {
    class Before: public FixtureSection {
    public:
        Before(Fixture* parent, Delegate& delegate, const char* file, uint32_t line);
        Before(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);
    private:
        void run(Reporter& reporter) const override;
    };
}
