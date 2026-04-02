#pragma once
#include <functional>

template <typename T>
class Testable {
    std::function<T()> testable;
    std::function<bool(T var)> test;
public:
    Testable(std::function<T()> testable, std::function<bool(T var)> test) : testable(testable), test(test) {}
    bool runTest(T val);
    bool runTest();
    T getDefault(T def);
public: // static    
    static T repeatUntilPass(const Testable<T>& testable);
};

template <typename T>
bool Testable<T>::runTest(T val) {
    return this->test(val);
}

template <typename T>
bool Testable<T>::runTest() {
    return this->runTest(this->testable());
}

template <typename T>
T Testable<T>::getDefault(T def) {
    T value = this->testable();
    return this->runTest(value) ? value : def;
}

template <typename T>
T Testable<T>::repeatUntilPass(const Testable<T>& testable) {
    T value;
    do {
        value = testable.testable();
    } while(!testable.test(value));
    return value;
}