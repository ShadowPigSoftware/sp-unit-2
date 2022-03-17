#pragma once

#include <stdint.h>
#include <string>
#include <list>

namespace SPUnit::Internal {
    template <class ...Args> constexpr void unused(Args&&...) {}
}