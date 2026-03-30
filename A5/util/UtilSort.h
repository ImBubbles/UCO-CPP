#pragma once
#include <functional>

namespace UtilSort {
    template <typename T>
    void insertionSort(T* arr, int n, const std::function<bool(T prev, T key)>& conditonal) {
        for(int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while(j >=0 && conditonal(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        }
    }
};

namespace PreparedSort {

    /*
    ltg = least to greatest
    gtl = greatest to least
    */

    template <typename T>
    void ltgInsertionSort(T* arr, int n) {
        return UtilSort::insertionSort(arr, n, std::function<bool(T, T)>([](T prev, T key) {
            return prev > key;
        }));
    }
    template <typename T>
    void gtlInsertionSort(T* arr, int n) {
        return UtilSort::insertionSort(arr, n, std::function<bool(T, T)>([](T prev, T key) {
            return prev < key;
        }));
    }
}