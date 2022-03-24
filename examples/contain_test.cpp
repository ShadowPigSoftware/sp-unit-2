#define SPUNIT_USE_MACROS
#include <spunit>

namespace {
    class CustomRangeBasedClass {
    private:
        const char* _value;
        uint32_t _length;
    public:
        CustomRangeBasedClass(const char* value, uint32_t length):
            _value(value) ,
            _length(length)
        {}

        using iterator = const char*;
        iterator begin() const {
            return _value;
        }

        iterator end() const
        {
            return _value + _length;
        }
    };

    class CustomContainsClass {
    public:
       bool contains(const std::string& value) const {
           return (value == "test");
       }

       bool contains(int value) const {
           return (value == 10 || value == 101);
       }
    };
}

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

    scenario("array") {
        const int array[7] = {1, 2, 3, 4, 5, 6, 7};
        expect(array).to.contain(3);  //True
        expect(array).to.contain(5);  //True

        expect(array).to.contain(0);  //False
        expect(array).to.contain(8);  //False
        expect(array).to.contain("Potato");  //False: No valid comparison on iterator, or contains method
    }

    scenario("range based STL container") {
        const std::list<int> list = {1, 2, 3, 4, 5, 6, 7};
        expect(list).to.contain(3);  //True
        expect(list).to.contain(5);  //True

        expect(list).to.contain(0);  //False
        expect(list).to.contain(8);  //False
        expect(list).to.contain("Potato");  //False: No valid comparison on iterator, or contains method
    }

    scenario("range based custom class") {
        const CustomRangeBasedClass custom = {"Hello", 4};
        expect(custom).to.contain('H');  //True
        expect(custom).to.contain('l');  //True

        expect(custom).to.contain('o');  //False: Due to length 4
        expect(custom).to.contain('z');  //False
        expect(custom).to.contain("Potato");  //False: No valid comparison on iterator, or contains method
    }

    scenario("contains custom class") {
        const CustomContainsClass custom;
        expect(custom).to.contain("test");  //True
        expect(custom).to.contain(10);  //True
        expect(custom).to.contain(101);  //True

        expect(custom).to.contain("Potato");  //False
        expect(custom).to.contain(11);  //False
        expect(custom).to.contain(CustomContainsClass {});  //False: Not iterable and no contains method
    }
}