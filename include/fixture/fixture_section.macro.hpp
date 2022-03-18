#pragma once
#include "common/common.macro.hpp"

#define SPUNIT_FIXTURE_SECTION_SELECT(...) SPUNIT_SELECT_CONCAT(_SPUNIT_FIXTURE_SECTION,SPUNIT_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define _SPUNIT_FIXTURE_SECTION_NAME(name, id) SPUNIT_CONCAT(name,id)
#define _SPUNIT_FIXTURE_SECTION_DELEGATE_CLASS_NAME(name, id) SPUNIT_CONCAT(name,_delegate_class_,id)
#define _SPUNIT_FIXTURE_SECTION_DELEGATE_NAME(name, id) SPUNIT_CONCAT(name,_delegate_,id)

#define _SPUNIT_FIXTURE_SECTION_DELEGATE_DECLARATION(name, className, id)\
    class _SPUNIT_FIXTURE_SECTION_DELEGATE_CLASS_NAME(name, id): public ::SPUnit::className::Delegate {\
        void function(const Utilities& spunit) override;\
    };\
    _SPUNIT_FIXTURE_SECTION_DELEGATE_CLASS_NAME(name, id) _SPUNIT_FIXTURE_SECTION_DELEGATE_NAME(name, id);


#define _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id,...)\
    _SPUNIT_FIXTURE_SECTION_DELEGATE_DECLARATION(name, className, id)\
    ::SPUnit::className _SPUNIT_FIXTURE_SECTION_NAME(name, id)= {_spunit_fixture, _SPUNIT_FIXTURE_SECTION_DELEGATE_NAME(name, id), __VA_ARGS__, __FILE__, __LINE__};\
    void _SPUNIT_FIXTURE_SECTION_DELEGATE_CLASS_NAME(name, id)::function(const Utilities& spunit)

#define _SPUNIT_BEFORE_EACH3(name, className, id)\
    _SPUNIT_FIXTURE_SECTION_DELEGATE_DECLARATION(name, className, id)\
    ::SPUnit::className _SPUNIT_FIXTURE_SECTION_NAME(name, id)= {_spunit_fixture, _SPUNIT_FIXTURE_SECTION_DELEGATE_NAME(name, id), __FILE__, __LINE__};\
    void _SPUNIT_FIXTURE_SECTION_DELEGATE_CLASS_NAME(name, id)::function(const Utilities& spunit)

#define _SPUNIT_FIXTURE_SECTION4(name, className, id, f) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f})
#define _SPUNIT_FIXTURE_SECTION5(name, className, id, f1, f2) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2})
#define _SPUNIT_FIXTURE_SECTION6(name, className, id, f1, f2, f3) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3})
#define _SPUNIT_FIXTURE_SECTION7(name, className, id, f1, f2, f3, f4) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3, #f4})
#define _SPUNIT_FIXTURE_SECTION8(name, className, id, f1, f2, f3, f4, f5) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3, #f4, #f5})
#define _SPUNIT_FIXTURE_SECTION9(name, className, id, f1, f2, f3, f4, f5, f6) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3, #f4, #f5, #f6})
#define _SPUNIT_FIXTURE_SECTION10(name, className, id, f1, f2, f3, f4, f5, f6, f7) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3, #f4, #f5, #f6, #f7})
#define _SPUNIT_FIXTURE_SECTION11(name, className, id, f1, f2, f3, f4, f5, f6, f7, f8) _SPUNIT_FIXURE_SECTION_FLAGS(name, className, id, {#f1, #f2, #f3, #f4, #f5, #f6, #f7, #f8})

#define SPUNIT_FIXTURE_SECTION(name, className, ...) SPUNIT_FIXTURE_SECTION_SELECT(name, className ,__COUNTER__, __VA_ARGS__)
