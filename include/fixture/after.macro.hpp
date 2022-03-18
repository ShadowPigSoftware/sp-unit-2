#pragma once
#include "fixture_section.macro.hpp"

#define SPUNIT_AFTER(...) SPUNIT_FIXTURE_SECTION(spu_after, After, __VA_ARGS__)
