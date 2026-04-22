#include <iostream>

// You can use this to learn structs

// A struct is created simply by typing 'struct' then the name of what you want to call it
// name it something meaningful not just Struct1
// common practice is to name using PascalCase/UppercaseCamelCase
// aka ThisIsHowYouWriteAName

struct Student {
    int age;
};
// end structs and classes with semi colon
// To create a class, you literally do the same
class Butterfly {
    int flaps;
};

int main() {
    // To initalize an object (create an object), there are a few options
    Student brody;
    Student carter = Student();
    // You can also use the 'new' keyword to create an object
    Student* hayden = new Student();

    // To call a member of a struct/class simply type <object name>.<member>
    // for example
    brody.age = 20;
    std::cout << brody.age << std::endl; // prints 20

    // make sure to delete anything you use the 'new' keyword on
    delete hayden;
    
    return 0;
}