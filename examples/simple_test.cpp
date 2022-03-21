#define SPUNIT_USE_MACROS
#include <spunit>

fixture("This is a simple fixture") {
    scenario("This is a successful scenario") {
        expect(1).to.equal(1);
    }
    
    scenario("This is a failing scenario") {
        expect(1).to.equal(0);
    }
}