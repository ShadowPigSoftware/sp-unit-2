#pragma once

#define _SPUNIT_CONCAT(name, num) name##num
#define SPUNIT_SELECT_CONCAT(name, num) _SPUNIT_CONCAT(name, num)
#define _SPUNIT_EXPAND(value) value
#define SPUNIT_SELECT(name, ...) SPUNIT_SELECT_CONCAT(name, SPUNIT_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)
#define SPUNIT_NUM_ARGS(...) SPUNIT_NUM_SELECT(__VA_ARGS__, 10,9,8,7,6,5,4,3,2,1,0)
#define SPUNIT_NUM_SELECT(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,...) a11

#define _SPUNIT_CONCAT0()
#define _SPUNIT_CONCAT1(a) a
#define _SPUNIT_CONCAT2(a,b) a##b
#define _SPUNIT_CONCAT3(a,b,c) a##b##c
#define _SPUNIT_CONCAT4(a,b,c,d) a##b##c##d
#define _SPUNIT_CONCAT5(a,b,c,d,e) a##b##c##d##e
#define _SPUNIT_CONCAT6(a,b,c,d,e,f) a##b##c##d##e##f
#define _SPUNIT_CONCAT7(a,b,c,d,e,f,g) a##b##c##d##e##f##g
#define _SPUNIT_CONCAT8(a,b,c,d,e,f,g,h) a##b##c##d##e##f##g##h
#define _SPUNIT_CONCAT9(a,b,c,d,e,f,g,h,i) a##b##c##d##e##f##g##h##i
#define _SPUNIT_CONCAT10(a,b,c,d,e,f,g,h,i,j) a##b##c##d##e##f##g##h##i##j

#define SPUNIT_CONCAT(...) SPUNIT_SELECT(_SPUNIT_CONCAT, __VA_ARGS__)