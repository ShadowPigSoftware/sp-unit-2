#include "runner/reporter.hpp"
#include "runner/null_output_stream.hpp"

namespace SPUnit {
    namespace {
        NullOutputStream nullOutputStream;
    }

    Reporter::Reporter():
        _stream {&nullOutputStream}
    {}

    OutputStream& Reporter::stream() {
        return *_stream;
    }

    void Reporter::setOutputStream(OutputStream& stream) {
        _stream = &stream;
    }
}
