#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class Reporter;
    class OutputStream;

    class Delegate {
    public:
        struct Utilities {
            Reporter& reporter;
            OutputStream& stream;
        };
        virtual ~Delegate() = default;
        virtual void function(const Utilities& utilities) = 0;
    };
}