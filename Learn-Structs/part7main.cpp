// This is the main reference file for part7, you can look at part7student.cpp and part7student.h if you would like
// This is just to show what it looks like when you keep the .cpp and .h for a class different than the main file

#include "part7student.h"
#include <iostream>

int main() {
    Student carter("Carter");
    std::cout << carter.getName() << std::endl; // Prints "Carter";
    return 0;
}

// Remember, to compile this so it works, you have to do this

// (for g++, clang is very similar though and for this should be interchangable)
// g++ part7main.cpp part7student.cpp -o output.exe
// the -o just means the file you run is titled "output.exe"