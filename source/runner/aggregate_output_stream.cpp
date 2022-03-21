#include "runner/aggregate_output_stream.hpp"
#include "runner/null_output_stream.hpp"

namespace SPUnit {    
    namespace {
        NullOutputStream nullOutputStream;
    }

    AggregateOutputStream::AggregateOutputStream():
        _outputStream {&nullOutputStream}
    {}

    AggregateOutputStream::AggregateOutputStream(OutputStream& outputStream):
        _outputStream {&outputStream}
    {}

    AggregateOutputStream& AggregateOutputStream::operator=(OutputStream& outputStream) {
        _outputStream = &outputStream;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (bool value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (short value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (unsigned short value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (int value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (unsigned int value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (long value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (unsigned long value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (std::size_t value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (float value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (double value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (long double value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (const char* value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (void* value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (Color value) {
        (*_outputStream) << value;
        return *this;
    }

    AggregateOutputStream& AggregateOutputStream::operator<< (Manipulator value) {
        (*_outputStream) << value;
        return *this;
    }
}
