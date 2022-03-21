#define SPUNIT_USE_MACROS
#include <spunit>

fixture("This is a simple fixture") {
    scenario("This is a simple scenario") {
        expect(uint8_t(5)).to.equal(6);
       // spunit.fail("Failure message", __LINE__);
    }
    
    scenario("This is a second scenario") {
        //spunit.fail("Another failure message", __LINE__);
    }
}