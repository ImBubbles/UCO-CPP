#include <iostream>

// You might realize an issue with the last code
// It would be very inconvinent to have to call Counter.reset() every time you make a new Counter
// This is when you create a 'Constructor'

class Counter {
    int value;
public:
// Constructors should be public except for rare exceptions
// But again, if you want to be able to call it outside of the class itself, you need it to be public

// To write a constructor, you simply act like you're making a new function
// This function, however, has no return type and is named the same exact as the class/struct itself
    Counter() { // This overrides the default construct (which does nothing) and says when the object is created, set value to 0
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
    Counter counter; // doing this sets value to 0
    std::cout << counter.getValue() << std::endl; // prints 0 because it was initialized to 0 by the constructor
    counter.count();
    counter.count();
    std::cout << counter.getValue() << std::endl; // prints 2
}