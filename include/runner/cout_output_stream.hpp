#pragma once

#include "output_stream.hpp"

namespace SPUnit {    
    class CoutOutputStream: public OutputStream {
    public:
        CoutOutputStream& operator<< (bool value) override;
        CoutOutputStream& operator<< (short value) override;
        CoutOutputStream& operator<< (unsigned short value) override;
        CoutOutputStream& operator<< (int value) override;
        CoutOutputStream& operator<< (unsigned int value) override;
        CoutOutputStream& operator<< (long value) override;
        CoutOutputStream& operator<< (unsigned long value) override;
        CoutOutputStream& operator<< (float value) override;
        CoutOutputStream& operator<< (double value) override;
        CoutOutputStream& operator<< (long double value) override;
        CoutOutputStream& operator<< (const char* value) override;
        CoutOutputStream& operator<< (void* value) override;
        CoutOutputStream& operator<< (Manipulator value) override;
    };
}
