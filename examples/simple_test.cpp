#define SPUNIT_USE_MACROS
#include <spunit>

fixture("This is a simple fixture") {
    scenario("This is a simple scenario") {
        char* x = "test";
        char* y = "test";
        expect(x).to.equal(y);
       // spunit.fail("Failure message", __LINE__);
    }
    
    scenario("This is a second scenario") {
        //spunit.fail("Another failure message", __LINE__);
    }
}