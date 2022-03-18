#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>

namespace SPUnit::Internal {
    template <class ...Args> constexpr void unused(Args&&...) {}
}