#pragma once

#include "output_stream.hpp"

#include "cout_output_stream_color_support_none.hpp"
#include "cout_output_stream_color_support_ansi8.hpp"

namespace SPUnit {    
    class CoutOutputStream: public OutputStream {
    public:
        struct ColorSupport {
            using None = CoutOutputStreamColorSupportNone;
            using Ansi8 = CoutOutputStreamColorSupportAnsi8;
        };
        CoutOutputStream(const CoutOutputStreamColorSupport& colorSupport = ColorSupport::None::instance);
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
        CoutOutputStream& operator<< (Color value) override;
        CoutOutputStream& operator<< (Manipulator value) override;
    private:
        const CoutOutputStreamColorSupport& _colorSupport;
    };
}
