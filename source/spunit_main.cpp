#include "spunit_main.hpp"
#include "runner/cout_output_stream.hpp"
#include "runner/spec_reporter.hpp"

namespace {
    ::SPUnit::SpecReporter defaultReporter;
    ::SPUnit::CoutOutputStream defaultOutputStream;
    ::SPUnit::Runner runner = {defaultReporter, defaultOutputStream};
}

int main(int argc, char** argv) {
    return spunit_main(runner, argc, argv);
}