#pragma once
#include "common/common.macro.hpp"

#define SPUNIT_FIXTURE_SELECT(...) SPUNIT_SELECT_CONCAT(_SPUNIT_FIXTURE, SPUNIT_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define _SPUNIT_FIXTURE_NAME(id) SPUNIT_CONCAT(spu_fixture_, SPU_NS,id)
#define _SPUNIT_FIXTURE_NAMESPACE_NAME(id) SPUNIT_CONCAT(,spu_fixture_ns_, SPU_NS,id)
#define _SPUNIT_FIXTURE_FLAGS_DECL(...) ::SPUnit::Fixture::Flags {__VA_ARGS__}

#define _SPUNIT_FIXTURE_FLAGS(id, description,...) \
    namespace SPUnit {\
        ::SPUnit::Fixture _SPUNIT_FIXTURE_NAME(id) = {_spunit_fixture, description, _SPUNIT_FIXTURE_FLAGS_DECL(__VA_ARGS__), __FILE__, __LINE__};\
    }\
    namespace SPUnit::_SPUNIT_FIXTURE_NAMESPACE_NAME(id) {\
        ::SPUnit::Fixture* const _spunit_fixture = &_SPUNIT_FIXTURE_NAME(id);\
    }\
    namespace SPUnit::_SPUNIT_FIXTURE_NAMESPACE_NAME(id)

#define _SPUNIT_FIXTURE2(id, description) \
    namespace SPUnit {\
        ::SPUnit::Fixture _SPUNIT_FIXTURE_NAME(id) = {_spunit_fixture, description, __FILE__, __LINE__};\
    }\
    namespace SPUnit::_SPUNIT_FIXTURE_NAMESPACE_NAME(id) {\
        ::SPUnit::Fixture* const _spunit_fixture = &_SPUNIT_FIXTURE_NAME(id);\
    }\
    namespace SPUnit::_SPUNIT_FIXTURE_NAMESPACE_NAME(id)

#define _SPUNIT_FIXTURE3(id, f, description) _SPUNIT_FIXTURE_FLAGS(id, description,#f)
#define _SPUNIT_FIXTURE4(id, f1, f2, description) _SPUNIT_FIXTURE_FLAGS(id, description,{#f1, #f2})
#define _SPUNIT_FIXTURE5(id, f1, f2, f3, description) _SPUNIT_FIXTURE_FLAGS(id, description,{#f1, #f2, #f3})
#define _SPUNIT_FIXTURE6(id, f1, f2, f3, f4, description) _SPUNIT_FIXTURE_FLAGS(id, description,#f1, #f2, #f3, #f4)
#define _SPUNIT_FIXTURE7(id, f1, f2, f3, f4, f5, description) _SPUNIT_FIXTURE_FLAGS(id, description,#f1, #f2, #f3, #f4, #f5)
#define _SPUNIT_FIXTURE8(id, f1, f2, f3, f4, f5, f6, description) _SPUNIT_FIXTURE_FLAGS(id, description,#f1, #f2, #f3, #f4, #f5, #f6)

#define SPUNIT_FIXTURE(...) SPUNIT_FIXTURE_SELECT(__COUNTER__, __VA_ARGS__)

