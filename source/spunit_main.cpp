#include "spunit_main.hpp"
#include "runner/cout_output_stream.hpp"
#include "runner/spec_reporter.hpp"
#include "runner/null_reporter.hpp"
#include "command-line/command_line_options.hpp"

namespace {
    ::SPUnit::Reporter* reporter;
    ::SPUnit::OutputStream* outputStream;
    ::SPUnit::CoutOutputStreamColorSupport* colorSupport;
    ::SPUnit::Runner* runner;

    bool processReporter(const std::string& reporterOption) {
        if (reporterOption == ::SPUnit::CommandLineOptions::reporterFlagNone)
        {
            reporter = new ::SPUnit::NullReporter;
        }
        else if (reporterOption == ::SPUnit::CommandLineOptions::reporterFlagSpec)
        {
            reporter = new ::SPUnit::SpecReporter;
        }
        else {
            return false;
        }
        return true;
    }

    bool processColor(const std::string& colorOption) {
        if (colorOption == ::SPUnit::CommandLineOptions::colorFlagNone)
        {
            colorSupport = new ::SPUnit::CoutOutputStream::ColorSupport::None;
        }
        else if (colorOption == ::SPUnit::CommandLineOptions::colorFlagAnsi8)
        {
            colorSupport = new ::SPUnit::CoutOutputStream::ColorSupport::Ansi8;
        }
        else if (colorOption == ::SPUnit::CommandLineOptions::colorFlagWindows)
        {
            colorSupport = new ::SPUnit::CoutOutputStream::ColorSupport::Windows;
        }
        else {
            return false;
        }
        return true;
    }

}

int main(int argc, char** argv) {
    ::SPUnit::CommandLineOptions options(argc, argv);

    if (!processReporter(options.reporter()))
    {
        std::cout << "Invalid reporter - " << options.reporter() << std::endl;
        return 1;
    }
    else if (!processColor(options.color()))
    {
        std::cout << "Invalid color - " << options.color() << std::endl;
        return 1;
    }

    outputStream = new ::SPUnit::CoutOutputStream {*colorSupport};
    runner = new ::SPUnit::Runner {*reporter, *outputStream};
    int output = spunit_main(*runner, argc, argv);

    delete runner;
    delete outputStream;
    delete colorSupport;
    delete reporter;

    return output;
}