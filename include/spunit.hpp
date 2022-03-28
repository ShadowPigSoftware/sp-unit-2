#pragma once

#include "fixture/fixture.hpp"
#include "fixture/before_each.hpp"
#include "fixture/after_each.hpp"
#include "fixture/before.hpp"
#include "fixture/after.hpp"
#include "scenario/scenario.hpp"
#include "runner/runner.hpp"
#include "runner/spec_reporter.hpp"
#include "runner/cout_output_stream.hpp"
#include "spunit_main.hpp"

#ifdef SPUNIT_USE_MACROS
#include "spunit_macros.hpp"
#endif