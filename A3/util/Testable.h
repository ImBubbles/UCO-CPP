#pragma once
#include <functional>

template <typename T>
class Testable {
    std::function<T()> testable;
    std::function<bool(T var)> test;
public:
    Testable(std::function<T()> testable, std::function<bool(T var)> test) : testable(testable), test(test) {}
public: // static    
    static T repeatUntilPass(Testable testable);
};

template <typename T>
T Testable<T>::repeatUntilPass(Testable<T> testable) {
    T value;
    do {
        value = testable.testable();
    } while(!testable.test(value));
    return value;
}