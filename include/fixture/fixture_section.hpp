#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "common/delegate.hpp"

namespace SPUnit {
    class Fixture;
    
    class FixtureSection: public Runnable {
    public:
        using Delegate = ::SPUnit::Delegate;
        FixtureSection(Fixture* parent, Delegate& delegate, const char* file, uint32_t line);
        FixtureSection(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);
    protected:
        Delegate& _delegate;
    };
}
