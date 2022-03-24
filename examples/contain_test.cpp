#define SPUNIT_USE_MACROS
#include <spunit>

fixture("Demonstration of the expect.to.contain functionality") {
    scenario("std::string") {
        expect(std::string("abc")).to.contain('a');  //True
        expect(std::string("abc")).to.contain("bc");  //True
        expect(std::string("abc")).to.contain(std::string("b"));  //True

        expect(std::string("abc")).to.contain('z');  //False
        expect(std::string("abc")).to.contain("def");  //False
        expect(std::string("abc")).to.contain(std::string("def"));  //False

        expect(std::string("abc")).to.contain(0x12345678);  //False: No find method  
    }
}