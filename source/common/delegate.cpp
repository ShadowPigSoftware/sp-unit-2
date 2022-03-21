#include "common/delegate.hpp"

namespace SPUnit {
    void Delegate::function(Reporter& reporter, OutputStream& stream) {
        spunit.reporter = reporter;
        spunit.stream = stream;
        function();
    }
}