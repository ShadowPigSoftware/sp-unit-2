#pragma once

#include "cout_output_stream_color_support_none.hpp"

#ifdef _WIN32
#include <Windows.h>
namespace SPUnit {    
    class CoutOutputStreamColorSupportWindows: public CoutOutputStreamColorSupport {
    public:
        CoutOutputStreamColorSupportWindows();
        void processColor(Color color, OutputStream& stream) const override;
    private:
        HANDLE _handle;
        CONSOLE_SCREEN_BUFFER_INFO _csbi;
    };
}
#else 
namespace SPUnit {    
    class CoutOutputStreamColorSupportWindows: public CoutOutputStreamColorSupportNone {};
}
#endif
