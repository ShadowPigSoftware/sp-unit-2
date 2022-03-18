#define SPUNIT_USE_MACROS
#include <spunit>

fixture("This is a simple fixture") {
    before() {
        spunit.stream << spunit.stream.grey << "Before" << spunit.stream.reset << spunit.stream.endl;
    }

    after() {
        spunit.stream << spunit.stream.white << "After" << spunit.stream.reset << spunit.stream.endl;
    }

    beforeEach() {
        spunit.stream << spunit.stream.yellow << "Before Each" << spunit.stream.endl;
    }

    afterEach() {
        spunit.stream << spunit.stream.blue << "After Each" << spunit.stream.endl;
    }

    scenario("This is a simple scenario") {
        spunit.stream << spunit.stream.cyan << "running scenario" << spunit.stream.endl;
    }
    
    scenario("This is a second scenario") {
        spunit.stream << spunit.stream.magenta << "running second scenario" << spunit.stream.endl;
    }
}