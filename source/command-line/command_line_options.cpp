#include "command-line/command_line_options.hpp"
namespace SPUnit {
    const std::string CommandLineOptions::reporterFlagPrefix = "--spunit-reporter=";
    const std::string CommandLineOptions::colorFlagPrefix = "--spunit-stream-color=";

    CommandLineOptions::CommandLineOptions(int argc, char** argv):
        _reporter(reporterFlagSpec),
        _color(colorFlagNone)
    {
        for (int i = 0; i < argc; ++i) {
            std::string argument = argv[i];
            if (argument.substr(0, reporterFlagPrefix.length()) == reporterFlagPrefix) {
                _reporter = argument.substr(reporterFlagPrefix.length());
            } else if (argument.substr(0, colorFlagPrefix.length()) == colorFlagPrefix) {
                _color = (argument.substr(colorFlagPrefix.length()));
            }
        }
    }

    const std::string& CommandLineOptions::reporter() const
    {
        return _reporter;
    }

    const std::string& CommandLineOptions::color() const
    {
        return _color;
    }
}