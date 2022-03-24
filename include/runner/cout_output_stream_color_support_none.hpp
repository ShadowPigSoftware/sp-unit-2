#pragma once

#include "cout_output_stream_color_support.hpp"

namespace SPUnit {    
    class CoutOutputStreamColorSupportNone: public CoutOutputStreamColorSupport {
    public:
        void processColor(Color color, OutputStream& stream) const override;
        static CoutOutputStreamColorSupportNone instance;
    };
}
