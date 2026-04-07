#pragma once
#include <functional>

namespace UtilSort {
    template <typename T>
    void insertionSort(T* arr, const int size, const std::function<bool(T& key, T& prev)>& conditonal) {
        for(int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        while(j >=0 && conditonal(arr[j], key)) { // should prev be shifted forward one
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        }
    }
    template <typename T>
    void selectionSort(T* arr, const int size, const std::function<bool(T& key, T& against)> conditional) {
        for(int i = 0; i < size -1; i++) {
            T swapPos = i;
            for(int j = i + 1; j < size; j++) {
                if(conditional(arr[j], arr[swapPos])) {
                    swapPos = j; // Should key swap with against? Against will be the lowest condition by the end of loop
                }
            }
            if(swapPos != i) {
                T temp = arr[i];
                arr[i] = arr[swapPos];
                arr[swapPos] = temp;
            }
        }
    }
    template <typename T>
    void bubbleSort(T* arr, const int size, const std::function<bool(T& current, T& next)> conditional) {
        for(int i = 0; i < size - 1; i++) {
            for(int j = 0; j < size - i -1; j++) {
                if(conditional(arr[j], arr[j + 1])) { // Should swap current with next?
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    namespace PreparedSort {
        // At least for now, these are all for numerical sorting

        /*
        ltg = least to greatest
        gtl = greatest to least
        */

        template <typename T>
        void ltgInsertionSort(T* arr, const int size) {
            return UtilSort::insertionSort(arr, size, std::function<bool(T&, T&)>([](T& key, T& prev) {
                return key > prev;
            }));
        }
        template <typename T>
        void gtlInsertionSort(T* arr, const int size) {
            return UtilSort::insertionSort(arr, size, std::function<bool(T&, T&)>([](T& key, T& prev) {
                return key < prev;
            }));
        }
        template <typename T>
        void ltgSelectionSort(T* arr, const int size) {
            return UtilSort::selectionSort(arr, size, std::function<bool(T&, T&)>([](T& key, T& against) {
                return against > key;
            }));
        }
        template <typename T>
        void gtlSelectionSort(T* arr, const int size) {
            return UtilSort::selectionSort(arr, size, std::function<bool(T&, T&)>([](T& key, T& against) {
                return against < key;
            }));
        }
        template <typename T>
        void ltgBubbleSort(T* arr, const int size) {
            return UtilSort::bubbleSort(arr, size, std::function<bool(T&, T&)>([](T& current, T& next) {
                return current > next;
            }));
        }
        template <typename T>
        void gtlBubbleSort(T* arr, const int size) {
            return UtilSort::bubbleSort(arr, size, std::function<bool(T&, T&)>([](T& current, T& next) {
                return current < next;
            }));
        }
    }
};