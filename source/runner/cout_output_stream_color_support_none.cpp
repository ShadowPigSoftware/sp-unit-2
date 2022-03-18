#include "runner/cout_output_stream_color_support_none.hpp"

namespace SPUnit {    
    void CoutOutputStreamColorSupportNone::processColor(Color color, CoutOutputStream& stream) const {
        Internal::unused(color, stream);
    }
        
    CoutOutputStreamColorSupportNone CoutOutputStreamColorSupportNone::instance;
}
