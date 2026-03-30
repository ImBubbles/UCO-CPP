/**
 * @file a4p1.cpp
 * @brief Main file for a5p1 assignment
 * @author Hayden Holmes
 * @date March 2026
 * @version 1.0
 * 
 * Roll a dice 20x, then print with parantheses around similar consecutive sequences
*/

#include "logger/Log.h" // Logging system
#include "util/UtilString.h" // String utility functions
#include "util/UtilNumber.h" // Number generation
#include <string> // Strings

/**
 * @brief Fill array randomly
 * @details Uses UtilNumber's randInt from util/UtilNumber.h
 * @param arr array to fill
 * @param n size of array
 * @return void
 */
void generateTosses(int* arr, int n) {
    for(int i = 0; i < 20; i++) { // Fill array with 'dice' rolls
        arr[i] = UtilNumber::randInt(1, 6);
    }
}

/**
 * @brief Prints array with parantheses around similar consecutive numbers
 * @details
 * Checks if the next number is the same, and if so starts a sequence (if not already not in a sequence)
 * If already in a sequence, check if the next number is different, if so end the sequence )
 * @param arr array to fill
 * @param n size of array
 * @return void
 */
void print_with_runs(int* arr, int n) {
    // Print array by grouping similar consecutive rolls in parentheses
    bool in = false;
    for(int i = 0; i < n; i++) {
        int c = arr[i]; // current
        int next = i < (n-1) ? arr[i + 1] : 0; // get next or 0 if none are next
        if(c == next && !in) { // Should start parentheses
            std::cout << "(" << c;
            in = true;
        } else if(c != next && in) { // Should end parentheses
            std::cout << c << ")";
            in = false;
        } else { // Default (just print the value / do nothing)
            std::cout << c;
        }
        std::cout << " "; // Space between each
    }
    std::cout << std::endl;
}

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    int arr[20];
    generateTosses(arr, 20); // generate tosses
    
    Log::debug("Array: " + UtilString::arrAsToString(arr, 20));

    print_with_runs(arr, 20); // print

    return 0;
    
}