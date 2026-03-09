#include "logger/Log.h"
#include "input/InputWrapper.h"
#include <iostream>

int main() {

    // Init logger
    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("debug is on");

    // Initialize variables
    long long result;
    long long clone;
    int checkSum;
    int remainder;
    while(true) {
        // Get ISBN
        result = InputWrapper::getLongLong("Enter the first 9 digits of an ISBN or type 0 to stop:");
        if(result == 0) { // Check for sentinel
            break;
        }
        clone = result;
        checkSum = 0;
        for(int i = 9; i > 0; i--) { // Get each digit and add to the checksum
            remainder = clone % 10;
            checkSum += remainder * i;
            clone /= 10;
        }
        checkSum %= 11; // Final part of checksum formula
        std::cout << "The ISBN-10 number is ";
        long long m = 100000000;
        while(m >= result) { // leading 0's
            std::cout << 0;
            m /= 10;
        }
        std::cout << result;
        std::cout << (checkSum == 10 ? "X" : "") << std::endl; // Print X if valid
    }

    return 0;
}