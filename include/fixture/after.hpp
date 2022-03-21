#pragma once

#include "fixture_section.hpp"

namespace SPUnit {
    class After: public FixtureSection {
    public:
        After(Fixture* parent, Delegate& delegate, const char* file, uint32_t line);
        After(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);
    private:
        void run(Reporter& reporter) override;
    };
}
