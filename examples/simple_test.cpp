#include <spunit>
#include <spunit-macros>
#include <iostream>

fixture("This is a simple fixture") {
    scenario("This is a simple scenario") {
        std::cout << "running scenario" << std::endl;
    }
}