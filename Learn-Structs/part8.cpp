// This is another part you don't need to know but is good to know
// Though it's less complicated than part 5 (const vs const)

// Having functions return references of values

// For context: there is a general rule of thumb for when to use a reference and value as a return
// If the type is smaller in size (typically int, double, char), use value -- these are considered cheap to copy
// If the type is bigger/unknown (typically vectors, strings, classes), use reference -- these are considered expensive to copy

#include <string>
#include <iostream>
// Very comparable to when you have to decide to pass by value or pass by reference
void example(const std::string& ref, int value) {} // string is a reference and int is a value

//// Note: this isn't replicable in normal functions (unless you use 'new')
//// This is because variables on the stack self-delete when they go out of scope, for example the function it's in ending
std::string& getMessage() { // <-- This function is not valid
    std::string result = "This is a message";
    return result;
}
// Error you get on this: Reference to stack memory associated with local variable 'result' returned

// The only time this is allowed within a class, is when the reference is to a class variable
// This is because the variable persists as long as the object is in memory

class Student {
    std::string name;
    int number;
public:
    Student(const std::string& name, int number) : name(name), number(number) {}
    const std::string& getName() { 
        return name; // Valid because it references std::string name of class Student
    }
    int getNumber() {
        return number;
    }
};

int main() {

    // All valid code below
    Student brody("Brody", 1);
    const std::string& name = brody.getName();
    std::cout << name << std::endl;

    return 0;
}