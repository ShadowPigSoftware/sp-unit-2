#pragma once

#include "delegate_utilities.hpp"

namespace SPUnit {
    class Delegate {
    public:
        using Utilities = DelegateUtilities;
        virtual ~Delegate() = default;
        virtual void function() const = 0;
    public:
        Utilities spunit;
    };
}