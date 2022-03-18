#pragma once
#include "fixture_section.macro.hpp"

#define SPUNIT_BEFORE_EACH(...) SPUNIT_FIXTURE_SECTION(spu_before_each, BeforeEach, __VA_ARGS__)
