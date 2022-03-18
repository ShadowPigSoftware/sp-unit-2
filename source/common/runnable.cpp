#include "common/runnable.hpp"
namespace SPUnit {
    Runnable::Runnable(Fixture* parent, const Flags& flags, const char* file, uint32_t line):
        _parent {parent},
        _flags {flags},
        _file {file},
        _line {line}
    {}
}
