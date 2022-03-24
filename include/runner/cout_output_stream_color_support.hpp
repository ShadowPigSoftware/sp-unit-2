#pragma once

#include "output_stream.hpp"

namespace SPUnit {    
    class OutputStream;
    class CoutOutputStreamColorSupport {
    public:
        using Color = OutputStream::Color;
        virtual ~CoutOutputStreamColorSupport() = default;
        virtual void processColor(Color value, OutputStream& stream) const = 0;
    };
}
