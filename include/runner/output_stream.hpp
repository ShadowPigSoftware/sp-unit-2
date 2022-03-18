#pragma once

#include "output_stream_color.hpp"

namespace SPUnit {    
    class OutputStream {
    public:
        virtual ~OutputStream() = default;

        using Color = OutputStreamColor;
        enum class Manipulator {
            Endl
        };
        virtual OutputStream& operator<< (bool value) = 0;
        virtual OutputStream& operator<< (short value) = 0;
        virtual OutputStream& operator<< (unsigned short value) = 0;
        virtual OutputStream& operator<< (int vavaluel) = 0;
        virtual OutputStream& operator<< (unsigned int value) = 0;
        virtual OutputStream& operator<< (long value) = 0;
        virtual OutputStream& operator<< (unsigned long value) = 0;
        virtual OutputStream& operator<< (float value) = 0;
        virtual OutputStream& operator<< (double value) = 0;
        virtual OutputStream& operator<< (long double value) = 0;
        virtual OutputStream& operator<< (const char* value) = 0;
        virtual OutputStream& operator<< (void* value) = 0;
        virtual OutputStream& operator<< (Manipulator value) = 0;
        virtual OutputStream& operator<< (Color value) = 0;

        static constexpr Manipulator endl = Manipulator::Endl;
        static constexpr Color reset = Color::Reset;
        static constexpr Color black = Color::Black;
        static constexpr Color grey = Color::Grey;
        static constexpr Color red = Color::Red;
        static constexpr Color green = Color::Green;
        static constexpr Color blue = Color::Blue;
        static constexpr Color cyan = Color::Cyan;
        static constexpr Color yellow = Color::Yellow;
        static constexpr Color magenta = Color::Magenta;
        static constexpr Color white = Color::White;
    };
}
