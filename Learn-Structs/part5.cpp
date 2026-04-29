#include <iostream>
// Feel free to skip this part.
// This is just some extra information that is good to know and you should know but maybe not yet

// using const in a class

// without knowing exactly how to use const in classes/structs, it can be confusing to read
// for example
struct Example {
    int value;
    int getValue() const {
        return value;
    }
    const int getValue() {
        return value;
    }
};

// both getValue() functions mean different things because of the way const is positioned
// The easiest one to understand is when const is at the front, this simply means the return type is const

// for example

struct Example2 {
    int value;
    const int getValue() {
        return value;
    }
};
// returns value as type 'const int'

// The other kind where it's at the end means the function does not modify anything
// This is somewhat important because if you ever have a instance of an object that is const, you can only call const functions
// For example

class Person{
    int age;
public:
    Person(int v) {
        age = v;
    }
    int getAge() {
        return age;
    }
    int getAge2() const {
        return age;
    }
};

int main() {

    Person brody(20);
    std::cout << brody.getAge() << std::endl; // valid code
    std::cout << brody.getAge2() << std::endl; // still valid code
    // a non-const object can call non-const and const functions

    const Person brodyConst = brody;
    //std::cout << brodyConst.getAge() << std::endl; // not valid code
    // compiler error: 'this' argument to member function 'getAge' has type 'const Person', but function is not marked const
    std::cout << brodyConst.getAge2() << std::endl; // valid code

    return 0;
}