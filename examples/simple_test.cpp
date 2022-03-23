#define SPUNIT_USE_MACROS
#include <spunit>

class Abc {};

const uint8_t array[4] = {1,2,3,4};

fixture("This is a simple fixture") {
    scenario("This is a successful scenario") {
        //expect(1.0).to.be.within(0.1).of(Abc {});
        // expect(1).to.equal(Abc {});
        //expect(array).to.contain("");
        expect(std::string("abc")).to.contain(5);
        // expect(1).to.be.lessThan(array);
    }
    
    scenario("This is a failing scenario") {
        expect(1.0).to.equal(1.0);
    }
}