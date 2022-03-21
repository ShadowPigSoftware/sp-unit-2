#include "scenario/scenario_delegate.hpp"

namespace SPUnit {
    void ScenarioDelegate::function(Scenario& scenario, Reporter& reporter, OutputStream& stream)   {
        spunit._scenario = &scenario;
        spunit.reporter = reporter;
        spunit.stream = stream;
        function();
    }
}