#include "logger/Log.h"
#include "util/UtilString.h"
#include "input/InputMenu.h"
#include "util/UtilSort.h"
#include <string>

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    const int size = 5;
    int arr[size] = {5, 2, 9, 1, 6};

    Log::info("Array before sorting: " + UtilString::arrAsToString(arr, size));

    std::string type;
    InputMenu* inputMenu = new InputMenu("Select Sorting Type");
    (*inputMenu)
    .addOption("Insertion Sort", [&type, &arr, size]() { type = "Insertion"; UtilSort::PreparedSort::ltgInsertionSort(arr, size); })
    .addOption("Selection Sort", [&type, &arr, size]() { type = "Selection"; UtilSort::PreparedSort::ltgInsertionSort(arr, size); })
    .addOption("Bubble Sort", [&type, &arr, size]() { type = "Bubble"; UtilSort::PreparedSort::ltgInsertionSort(arr, size); });
    inputMenu->prompt();
    delete inputMenu;

    Log::info("Array after sorting using " + type + " sort: " + UtilString::arrAsToString(arr, size));

    return 0;
    
}