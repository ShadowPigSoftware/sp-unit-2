#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>
#include <fcntl.h>

namespace SPUnit::Internal {
    template <class ...Args> constexpr void unused(Args&&...) {}
}