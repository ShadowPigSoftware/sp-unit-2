#pragma once
#include "common/common.macro.hpp"

#define SPUNIT_SCENARIO_SELECT(...) SPUNIT_SELECT_CONCAT(_SPUNIT_SCENARIO, SPUNIT_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define _SPUNIT_SCENARIO_NAME(id) SPUNIT_CONCAT(spu_scenario_,id)
#define _SPUNIT_SCENARIO_FUNCTION_NAME(id) SPUNIT_CONCAT(spu_scenario_func_,id)

#define _SPUNIT_SCENARIO_FLAGS(id, description,...) \
   void _SPUNIT_SCENARIO_FUNCTION_NAME(id)();\
    ::SPUnit::Scenario _SPUNIT_SCENARIO_NAME(id)= {_spunit_fixture, description, _SPUNIT_SCENARIO_FUNCTION_NAME(id), __VA_ARGS__, __FILE__, __LINE__};\
    void _SPUNIT_SCENARIO_FUNCTION_NAME(id)()

#define _SPUNIT_SCENARIO2(id, description) \
    void _SPUNIT_SCENARIO_FUNCTION_NAME(id)();\
    ::SPUnit::Scenario _SPUNIT_SCENARIO_NAME(id)= {_spunit_fixture, description, _SPUNIT_SCENARIO_FUNCTION_NAME(id), __FILE__, __LINE__};\
    void _SPUNIT_SCENARIO_FUNCTION_NAME(id)()

#define _SPUNIT_SCENARIO3(id, f, description) _SPUNIT_SCENARIO_FLAGS(id, description,{#f})
#define _SPUNIT_SCENARIO4(id, f1, f2, description) _SPUNIT_SCENARIO_FLAGS(id, description,{#f1, #f2})
#define _SPUNIT_SCENARIO5(id, f1, f2, f3, description) _SPUNIT_SCENARIO_FLAGS(id, description,{#f1, #f2, #f3})
#define _SPUNIT_SCENARIO6(id, f1, f2, f3, f4, description) _SPUNIT_SCENARIO_FLAGS(id, description,#f1, #f2, #f3, #f4)
#define _SPUNIT_SCENARIO7(id, f1, f2, f3, f4, f5, description) _SPUNIT_SCENARIO_FLAGS(id, description,#f1, #f2, #f3, #f4, #f5)
#define _SPUNIT_SCENARIO8(id, f1, f2, f3, f4, f5, f6, description) _SPUNIT_SCENARIO_FLAGS(id, description,#f1, #f2, #f3, #f4, #f5, #f6)

#define SPUNIT_SCENARIO(...) SPUNIT_SCENARIO_SELECT(__COUNTER__, __VA_ARGS__)
