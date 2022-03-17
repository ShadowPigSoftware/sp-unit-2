#pragma once

#include "spunit_core.hpp"

namespace SPUnit {    
    class OutputStream {
    public:
        virtual ~OutputStream() = default;

        enum class Manipulator {
            Endl
        };
        virtual OutputStream& operator<< (bool value) = 0;
        virtual OutputStream& operator<< (short value) = 0;
        virtual OutputStream& operator<< (unsigned short value) = 0;
        virtual OutputStream& operator<< (int vavaluel) = 0;
        virtual OutputStream& operator<< (unsigned int value) = 0;
        virtual OutputStream& operator<< (long value) = 0;
        virtual OutputStream& operator<< (unsigned long value) = 0;
        virtual OutputStream& operator<< (float value) = 0;
        virtual OutputStream& operator<< (double value) = 0;
        virtual OutputStream& operator<< (long double value) = 0;
        virtual OutputStream& operator<< (const char* value) = 0;
        virtual OutputStream& operator<< (void* value) = 0;
        virtual OutputStream& operator<< (Manipulator value) = 0;

        static constexpr Manipulator endl = Manipulator::Endl;
    };
}
