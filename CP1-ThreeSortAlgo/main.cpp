#include "logger/Log.h"
#include "util/UtilString.h"
#include "util/UtilNumber.h"
#include "util/UtilSort.h"
#include <string>

void bubbleSort(int* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i -1; j++) {
            Log::debug(UtilString::rightString(15, UtilString::arrAsToString(arr, 5), ' '));
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    int arr[5] = {5, 2, 9, 1, 6};
    //selectionSort(arr, 5);
    //PreparedSort::ltgSelectionSort(arr, 5);
    bubbleSort(arr, 5);
    Log::debug(UtilString::rightString(15, UtilString::arrAsToString(arr, 5), ' '));

    return 0;
    
}