#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "common/delegate.hpp"

namespace SPUnit {
    class Fixture;
    
    class FixtureSection: public Runnable {
    public:
        using Flags = CommonFlags;
        using Delegate = ::SPUnit::Delegate;
        FixtureSection(Fixture* parent, Delegate& delegate, const char* file, uint32_t line);
        FixtureSection(Fixture* parent, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);
    private:
        const Fixture* const _parent;
    protected:
        Delegate& _delegate;
    private:
        const Flags _flags;
        const char* const _file;
        const uint32_t _line;
    };
}
