#pragma once

#include "scenario_delegate_utilities.hpp"
#include "expect/expect.hpp"

namespace SPUnit {
    class Scenario;

    class ScenarioDelegate {
    public:
        using Utilities = ScenarioDelegateUtilities;
        virtual ~ScenarioDelegate() = default;
        virtual void function() = 0;
        void function(Scenario& scenario, Reporter& reporter, OutputStream& stream);
    public:
        Utilities spunit;
    };
}