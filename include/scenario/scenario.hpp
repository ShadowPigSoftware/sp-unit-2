#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "common/delegate.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario: public Runnable {
    public:
        using Flags = CommonFlags;
        using Delegate = ::SPUnit::Delegate;
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const char* file, uint32_t line);
        Scenario(Fixture* parent, const char* description, Delegate& delegate, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;
    private:
        void run(Reporter& reporter) const override;
    private:
        const Fixture* const _parent;
        const char* const _description;
        Delegate& _delegate;
        const Flags _flags;
        const char* const _file;
        const uint32_t _line;
    };
}