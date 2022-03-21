#include "runner/cout_output_stream.hpp"

#include <iostream>

namespace SPUnit {    
    CoutOutputStream::CoutOutputStream(const CoutOutputStreamColorSupport& colorSupport):
        _colorSupport {colorSupport}
    {}

    CoutOutputStream& CoutOutputStream::operator<< (bool value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (short value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (unsigned short value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (int value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (unsigned int value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (long value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (unsigned long value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (std::size_t value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (float value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (double value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (long double value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (const char* value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (void* value) {
        std::cout << value;
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (Color value) {
        _colorSupport.processColor(value, *this);
        return *this;
    }

    CoutOutputStream& CoutOutputStream::operator<< (Manipulator value) {
        switch (value) {
        case Manipulator::Endl:
            std::cout << std::endl;
            break;
        }

        return *this;
    }
}
