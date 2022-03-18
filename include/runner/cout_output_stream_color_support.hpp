#pragma once

#include "output_stream.hpp"

namespace SPUnit {    
    class CoutOutputStream;
    class CoutOutputStreamColorSupport {
    public:
        using Color = OutputStream::Color;
        virtual ~CoutOutputStreamColorSupport() = default;
        virtual void processColor(Color value, CoutOutputStream& stream) const = 0;
    };
}
