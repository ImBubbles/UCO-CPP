/**
 * @file main3.cpp
 * @brief Progamming Assignment 2.19.3
 * @author Hayden Holmes
 * @date February 2025
 * @version 1.0
 * 
 * Using a ceiling of 75, calculate discount using rentals + referrals.
*/

#include <string> // for string datatype
#include "logger/Log.h" // More robust logging
#include "input/InputWrapper.h" // Easy to use inputwrapper that handles edge cases

// Instead of including the whole <algorithm> header, just use these easy functions (saves on compile time & file size) 
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    // Init logger
    //Log::LOG_FILTER = -1; // Comment this out to get rid of debug lines
    Log::defaultLogger(); // Use cout

    int rentals = InputWrapper::getInteger("Enter the number of movie rentals:");
    Log::debug("Rentals = " + std::to_string(rentals));
    int referrals = InputWrapper::getInteger("Enter the number of members referred to the video club:");
    Log::debug("Referrals = " + std::to_string(referrals));

    int discount = min(rentals + referrals, 75);

    Log::info("The discount is equal to " + std::to_string(discount) + " percent");
    

    return 0;
}