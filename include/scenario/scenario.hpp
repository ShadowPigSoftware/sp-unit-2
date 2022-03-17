#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"

namespace SPUnit {
    class Fixture;
    class Scenario: public Runnable {
    public:
        using Flags = CommonFlags;
        using Function = void(*)();
        Scenario(Fixture* parent, const char* description, Function function, const char* file, uint32_t line);
        Scenario(Fixture* parent, const char* description, Function function, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;
    private:
        void run(Reporter& reporter, OutputStream& stream) const;
    private:
        const Fixture* const _parent;
        const char* const _description;
        Function _function;
        const Flags _flags;
        const char* const _file;
        const uint32_t _line;
    };
}