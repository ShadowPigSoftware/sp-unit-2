#include "runner/cout_output_stream_color_support_ansi8.hpp"
#include "runner/cout_output_stream.hpp"

namespace SPUnit {    
    void CoutOutputStreamColorSupportAnsi8::processColor(Color color, CoutOutputStream& stream) const {
        switch (color) {
        case Color::Reset:
            stream << "\u001b[0m";
            break;
        case Color::Black:
            stream << "\u001b[30m";
            break;
        case Color::Grey:
            stream << "\u001b[30;1m";
            break;
        case Color::Red:
            stream << "\u001b[31m";
            break;
        case Color::Green:
            stream << "\u001b[32m";
            break;
        case Color::Blue:
            stream << "\u001b[34m";
            break;
        case Color::Cyan:
            stream << "\u001b[36m";
            break;
        case Color::Yellow:
            stream << "\u001b[33m";
            break;
        case Color::Magenta:
            stream << "\u001b[35m";
            break;
        case Color::White:
            stream << "\u001b[37m";
            break;
        default:
            break;
        }
    }
}
