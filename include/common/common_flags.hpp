#pragma once

#include "spunit_core.hpp"

namespace SPUnit {
    class CommonFlags {
    private:
        using FlagList = std::list<const char*>; 
    public:
        using const_iterator = FlagList::const_iterator;
        CommonFlags(std::initializer_list<const char*> flags);

        const_iterator begin() const;
        const_iterator end() const;

        bool contains(const char* value) const;

        static constexpr const char* skip = "skip";
        static constexpr const char* failOnFirstError = "fail-on-first-error";
    private:
        FlagList _flags;
    };
}