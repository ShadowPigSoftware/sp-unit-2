#pragma once

#include "output_stream.hpp"

namespace SPUnit {    
    class AggregateOutputStream: public OutputStream {
    public:
        AggregateOutputStream();
        AggregateOutputStream(OutputStream& outputStream);
        AggregateOutputStream& operator=(OutputStream& outputStream);

        AggregateOutputStream& operator<< (bool value) override;
        AggregateOutputStream& operator<< (short value) override;
        AggregateOutputStream& operator<< (unsigned short value) override;
        AggregateOutputStream& operator<< (int value) override;
        AggregateOutputStream& operator<< (unsigned int value) override;
        AggregateOutputStream& operator<< (long value) override;
        AggregateOutputStream& operator<< (unsigned long value) override;
        AggregateOutputStream& operator<< (std::size_t value) override;
        AggregateOutputStream& operator<< (float value) override;
        AggregateOutputStream& operator<< (double value) override;
        AggregateOutputStream& operator<< (long double value) override;
        AggregateOutputStream& operator<< (const char* value) override;
        AggregateOutputStream& operator<< (void* value) override;
        AggregateOutputStream& operator<< (Color value) override;
        AggregateOutputStream& operator<< (Manipulator value) override;
    private:
        OutputStream* _outputStream;
    };
}
