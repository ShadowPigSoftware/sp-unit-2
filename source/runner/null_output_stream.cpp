#include "runner/null_output_stream.hpp"

#include <iostream>

namespace SPUnit {    
    NullOutputStream& NullOutputStream::operator<< (bool value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (short value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (unsigned short value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (int value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (unsigned int value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (long value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (unsigned long value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (std::size_t value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (float value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (double value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (long double value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (const char* value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (void* value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (Color value) {
        Internal::unused(value);
        return *this;
    }

    NullOutputStream& NullOutputStream::operator<< (Manipulator value) {
        Internal::unused(value);
        return *this;
    }
}
