#pragma once

#include "delegate_utilities.hpp"

namespace SPUnit {
    class Delegate {
    public:
        using Utilities = DelegateUtilities;
        virtual ~Delegate() = default;
        virtual void function() = 0;
        void function(Reporter& reporter, OutputStream& stream);
    public:
        Utilities spunit;
    };
}