#include "fixture/fixture.macro.hpp"
#include "fixture/before_each.macro.hpp"
#include "fixture/after_each.macro.hpp"
#include "fixture/before.macro.hpp"
#include "fixture/after.macro.hpp"
#include "scenario/scenario.macro.hpp"
#include "expect/expect.macro.hpp"

#define fixture SPUNIT_FIXTURE
#define scenario SPUNIT_SCENARIO
#define beforeEach SPUNIT_BEFORE_EACH
#define afterEach SPUNIT_AFTER_EACH
#define before SPUNIT_BEFORE
#define after SPUNIT_AFTER
#define expect SPUNIT_EXPECT