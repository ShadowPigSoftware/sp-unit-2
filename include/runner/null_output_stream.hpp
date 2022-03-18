#pragma once

#include "output_stream.hpp"

namespace SPUnit {    
    class NullOutputStream: public OutputStream {
    public:
        NullOutputStream& operator<< (bool value) override;
        NullOutputStream& operator<< (short value) override;
        NullOutputStream& operator<< (unsigned short value) override;
        NullOutputStream& operator<< (int value) override;
        NullOutputStream& operator<< (unsigned int value) override;
        NullOutputStream& operator<< (long value) override;
        NullOutputStream& operator<< (unsigned long value) override;
        NullOutputStream& operator<< (float value) override;
        NullOutputStream& operator<< (double value) override;
        NullOutputStream& operator<< (long double value) override;
        NullOutputStream& operator<< (const char* value) override;
        NullOutputStream& operator<< (void* value) override;
        NullOutputStream& operator<< (Color value) override;
        NullOutputStream& operator<< (Manipulator value) override;
    };
}
