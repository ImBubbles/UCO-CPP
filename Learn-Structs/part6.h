#pragma once
#include <string>
class Student {
    std::string name; // just a reminder, this is private
public: // now this is public
    // Note: Below uses the member initializer list
    // This avoids creating a temporary default value for the members first
    // This code also runs before the actual content within the constructor
    Student(std::string name) : name(name) {} // This constructor is considered defined because it has '{}'
    // Also note, you cannot use the member initializer list and keep the constructor a prototype

    // Syntax of member initializer list:
    // ClassName(std::string parameter) : member(parameter) {}

    std::string getName(); // prototype of getter for name variable
    void setName(std::string); // prototype of setter for name variable
};