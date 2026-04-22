#include <iostream>

// You can 'overload' functions in classes same as you can normally outside of classes
// Very importantly, this includes the constructor

// For example
// Here is how you would normally overload a function
void add(int a, int b, int* result) {
    *result = a + b;
}
void add(int a, int b, int c, int* result) {
    *result = a + b + c;
}

// You can replicate this in a class
// We will reuse the Counter class for this
class Counter{
    int value;
public:
    Counter() { // what we did before
        value = 0;
    }
    Counter(int v) { // this overloads and makes another way to initialize the object
        value = v;
    }
    const int getValue() {
        return value;
    }
    void count() {
        value++;
    }
    void count(int amt) { // overloading function count()
        value += amt;
    }
};

int main() {

    // How to initalize with a constructor that has parameters
    Counter c1(5);
    Counter c2 = Counter(3);
    Counter* c3 = new Counter(7);

    // Just a reminder, this is still valid
    Counter c4; // still initailizes value as 0

    // And calling an overloaded function is still same as before
    std::cout << c1.getValue() << std::endl; // prints 5
    c1.count(); // still works
    std::cout << c1.getValue() << std::endl; // prints 6
    c1.count(2); // also works but with different functionality now
    std::cout << c1.getValue() << std::endl; // prints 8

    return 0;
}