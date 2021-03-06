#pragma once

#include <stdint.h>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fcntl.h>
#include <type_traits>

namespace SPUnit::Internal {
    template <class ...Args> constexpr void unused(Args&&...) {}
}