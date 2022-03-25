#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class CommandLineOptions {
    private:
        static const std::string reporterFlagPrefix;
        static const std::string colorFlagPrefix;
    public:
        static constexpr const char* reporterFlagNone = "none";
        static constexpr const char* reporterFlagSpec = "spec";  

         static constexpr const char* colorFlagNone = "none";
        static constexpr const char* colorFlagAnsi8 = "ansi8";
        static constexpr const char* colorFlagWindows = "windows";

        CommandLineOptions(int argc, char** argv);

        const std::string& reporter() const;
        const std::string& color() const;
    private:
        std::string _reporter;
        std::string _color;
    };
}