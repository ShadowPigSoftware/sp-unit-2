#pragma once
#include "fixture_section.macro.hpp"

#define SPUNIT_AFTER_EACH(...) SPUNIT_FIXTURE_SECTION(spu_after_each, AfterEach, __VA_ARGS__)
