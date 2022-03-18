#pragma once

#include "cout_output_stream_color_support.hpp"

namespace SPUnit {    
    class CoutOutputStreamColorSupportAnsi8: public CoutOutputStreamColorSupport {
    public:
        void processColor(Color color, CoutOutputStream& stream) const override;
    };
}
