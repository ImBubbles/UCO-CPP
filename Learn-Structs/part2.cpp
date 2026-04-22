#include <iostream>

// The only difference between class and struct is two simple things
// struct starts as public and cannot use templates
// class starts as private and can use templates
// In all other ways they are the same
// do not worry about what templates are right now, you probably won't touch that for awhile

// for example
class Person { // class starts as private
    int age;
public: // anything written below this will be public
    int funnyNumber;
private: // you can switch back to private/public as many times as you want
    int otherNumber;
};

void example() {
    Person myPerson;
    // Here's some examples of valid and invalid code
    myPerson.funnyNumber = 80; // Valid because funnyNumber is public
    //myPerson.age = 19 // Not valid because age is private (though not explicity said private:, classes start as private)
    //myPerson.otherNumber = 100; // Not valid because it is private
}

// So when do we use private or public???
// private is best when you want to be clear the 'member' should not be modified directly or just to be safe
// for example, age usually would not be public even though some might assume so
// We would create what are called getters/setters
// Another example would be when you want the code within the class be able to modify the member variable (meaning it can't be const)
// But you don't want code outside of the class to be able to modify it
// BUT you still want to be able to get the VALUE of the member variable

// Example of this

class Counter{
    int value;
public:
    void reset() {
        value = 0;
    }
    const int getValue() {
        return value;
    }
    void count() {
        value++;
    }
};

int main() {

    Counter c;
    c.reset();
    std::cout << c.getValue() << std::endl; // prints 0
    c.count();
    c.count();
    std::cout << c.getValue() << std::endl; // prints 2

    return 0;
}