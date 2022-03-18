#include "common/common_flags.hpp"

namespace SPUnit {
    CommonFlags::CommonFlags(std::initializer_list<const char*> flags):
        _flags {flags}
    {}

    CommonFlags::const_iterator CommonFlags::begin() const {
        return _flags.begin();
    }

    CommonFlags::const_iterator CommonFlags::end() const {
        return _flags.end();
    }

    bool CommonFlags::contains(const char* value) const {
        for (auto flag: _flags)
        {
            if (std::strcmp(flag, value) == 0) {
                return true;
            }
        }
        return false;
    }
}