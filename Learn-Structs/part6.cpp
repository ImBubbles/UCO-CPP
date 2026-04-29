// You may notice there is also a part6.h for this
// Both of these files are used typically to create classes

//// A few basic bits of information that you may be clear some confusion
// You can define classes in .h files without using a respective .cpp file
// It is common to define some more simplistic methods in the .h whilst more advanced functions are defined in .cpp
// It is also common to define everything in the .cpp and keep everything in the .h a prototype

// What it looks like to compile?
// g++ main.cpp student.cpp
// Note: do NOT compile .h files
// when a file such as main.cpp includes student.h, the compiler acts like everything from student.h is at the top of main.cpp

// To avoid compiler conflicts with multiple includes, always do one of these
// A: have the very first line of the .h be '#pragma once'
// B: have the very first 2 lines of the .h be 'ifndef MY_HEADER_H' & '#define MY_HEADER_H' and the very last line be '#endif'
// I recommend '#pragma once' because it's easier
// Note: '#pragma once' is not considered standard C++, it is something that SOME compilers have as a feature

// Example of respective .cpp code to a .h
// You must include the .h using quotation marks like so
#include <iostream> // You should have you're std includes above you're .h includes, typically at least, doesn't really matter
#include "part6.h"
// Now to define functions from the class
// Syntax:
// returntype ClassName::FunctionName(parameters) {}
// Like so
std::string Student::getName() {
    return name;
}
// Note: any includes from .h such as #include <string>, will also be included in anything calling #include "part6.h"
void Student::setName(std::string name) {
    this->name = name; // When defining a member function, you can use the keyword 'this'
    // 'this' gets a pointer to the instance when the code is ran
}

int main() {

    Student carter("Carter");
    std::cout << carter.getName() << std::endl; // prints "Carter"

    return 0;
}