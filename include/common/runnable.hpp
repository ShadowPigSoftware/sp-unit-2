#pragma once

#include "common_flags.hpp"

namespace SPUnit {
    class Reporter;
    class Fixture;

    class Runnable {
        friend class Fixture; //The Fixture class is access any runnable;
    public:
        using Flags = CommonFlags;
    protected:
        Runnable(Fixture* parent, const Flags& flags, const char* file, uint32_t line);
        virtual ~Runnable() = default;
        
        virtual void run(Reporter& reporter) = 0;
        const Fixture* const _parent;
        const Flags _flags;
        const char* const _file;
        const uint32_t _line;
    };
}
