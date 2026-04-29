#pragma once
#include <string>
class Student {
    std::string name;
public:
    Student(std::string name) : name(name) {}
    std::string getName();
    void setName(std::string);
};