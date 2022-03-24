#include <spunit>

namespace {
    ::SPUnit::CoutOutputStream::ColorSupport::Windows colorSupport;
    ::SPUnit::CoutOutputStream outputStream(colorSupport);
    ::SPUnit::SpecReporter spec("+", "-");
}

int spunit_main(::SPUnit::Runner& runner, int argc, char** argv) {
    (void)argc;
    (void)argv;

    runner.setReporter(spec);
    runner.setOutputStream(outputStream);
    return runner.run();
}