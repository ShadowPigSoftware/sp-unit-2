#define SPUNIT_USE_MACROS
#include <spunit>

class Abc {};

fixture("This is a simple fixture") {
    scenario("This is a successful scenario") {
        expect(1.9).to.be.within(0.000001).of(1.89999999999);
    }
    
    scenario("This is a failing scenario") {
        expect(1).to.be.lessThan(0);
    }
}