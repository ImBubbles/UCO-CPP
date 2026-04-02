#pragma once
#include <vector>
#include <functional>

template <typename T>
class Iterator {
    std::vector<T> list;
    public:
    Iterator(std::vector<T> list) : list(list) {}
    void overAll(std::function<void(T& element)> exec) {
        for(T element : list) {
            exec(element);
        }
    }
    void overConditional(std::function<void(T& element)> exec, std::function<bool(const T& element)> conditional) {
        for(T element : list) {
            if(!conditional(element)) {
                continue;
            }
            exec(element);
        }
    }
    void overSublist(std::function<void(T& element)> exec, int start, int end) { // [INCLUSIVE, EXCLUSIVE)
        for(int i = start; i < end || i < list.size(); i++) {
            exec(list[i]);
        }
    }
};