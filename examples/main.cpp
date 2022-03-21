#include <spunit>

namespace {
    ::SPUnit::CoutOutputStream::ColorSupport::Ansi8 ansi8;
    ::SPUnit::CoutOutputStream outputStream(ansi8);
    //::SPUnit::SpecReporter spec("+", "-");
    ::SPUnit::SpecReporter spec;
}

int spunit_main(::SPUnit::Runner& runner, int argc, char** argv) {
    (void)argc;
    (void)argv;
    runner.setReporter(spec);
    runner.setOutputStream(outputStream);
    return runner.run();
}