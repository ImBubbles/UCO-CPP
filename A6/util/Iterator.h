#pragma once
#include <vector>
#include <functional>
#include "Completable.h"

template <typename T>
class Iterator {
    std::vector<T> list;
    public:
    Iterator(std::vector<T> list) : list(list) {}
    Iterator(T* list, const int size) : list(std::vector<T>(list, list + size)) {}
    Completable::CompletableFuture<void*, void*> overAll(std::function<void(T& element)> exec) {
        for(T element : list) {
            exec(element);
        }
        return Completable::CompletableFuture<void*, void*>(nullptr);
    }
    Completable::CompletableFuture<void*, void*> overConditional(std::function<void(T& element)> exec, std::function<bool(const T& element)> conditional) {
        for(T element : list) {
            if(!conditional(element)) {
                continue;
            }
            exec(element);
        }
        return Completable::CompletableFuture<void*, void*>(nullptr);
    }
    Completable::CompletableFuture<void*, void*> overSublist(std::function<void(T& element)> exec, int start, int end) { // [INCLUSIVE, EXCLUSIVE)
        for(int i = start; i < end || i < list.size(); i++) {
            exec(list[i]);
        }
        return Completable::CompletableFuture<void*, void*>(nullptr);
    }
};