#pragma once
#include "fixture_section.macro.hpp"

#define SPUNIT_BEFORE(...) SPUNIT_FIXTURE_SECTION(spu_before, Before, __VA_ARGS__)
