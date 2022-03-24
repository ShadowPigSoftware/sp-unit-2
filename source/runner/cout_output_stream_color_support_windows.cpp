#include "runner/cout_output_stream_color_support_windows.hpp"
#include "runner/cout_output_stream.hpp"

#ifdef _WIN32
namespace SPUnit {    
    CoutOutputStreamColorSupportWindows::CoutOutputStreamColorSupportWindows():
        _handle {::GetStdHandle(STD_OUTPUT_HANDLE)}
    {
        GetConsoleScreenBufferInfo(_handle, &_csbi );
    }
        
    void CoutOutputStreamColorSupportWindows::processColor(Color color, OutputStream& stream) const {
        Internal::unused(stream);
        switch (color) {
        case Color::Reset:
            SetConsoleTextAttribute(_handle, _csbi.wAttributes);
            break;
        case Color::Black:
            SetConsoleTextAttribute(_handle, 0);
            break;
        case Color::Grey:
            SetConsoleTextAttribute(_handle, 8);
            break;
        case Color::Red:
            SetConsoleTextAttribute(_handle, 4);
            break;
        case Color::Green:
            SetConsoleTextAttribute(_handle, 2);
            break;
        case Color::Blue:
            SetConsoleTextAttribute(_handle, 1);
            break;
        case Color::Cyan:
            SetConsoleTextAttribute(_handle, 3);
            break;
        case Color::Yellow:
            SetConsoleTextAttribute(_handle, 6);
            break;
        case Color::Magenta:
            SetConsoleTextAttribute(_handle, 5);
            break;
        case Color::White:
            SetConsoleTextAttribute(_handle, 7);
            break;
        default:
            break;
        }   
    }
}
#endif