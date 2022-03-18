#define SPUNIT_USE_MACROS
#include <spunit>

fixture("This is a simple fixture") {
    before() {
        spunit.stream << "Before" << spunit.stream.endl;
    }

    after() {
        spunit.stream << "After" << spunit.stream.endl;
    }

    beforeEach() {
        spunit.stream << "Before Each" << spunit.stream.endl;
    }

    afterEach() {
        spunit.stream << "After Each" << spunit.stream.endl;
    }

    scenario(skip, "This is a simple scenario") {
        spunit.stream << "running scenario" << spunit.stream.endl;
    }
    
    scenario("This is a second scenario") {
        spunit.stream << "running second scenario" << spunit.stream.endl;
    }
}