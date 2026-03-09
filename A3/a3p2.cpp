/**
 * @file a3p2.cpp
 * @brief Assignment 3 Part 2
 * @author Hayden Holmes
 * @date February 2026
 * @version 1.0
 * 
 * Lists all prime factors before
*/

#include "logger/Log.h"
#include "input/InputWrapper.h"
#include "util/Testable.h"

bool hasFactors(int i) {
    for(int j = 2; j < i; j++) {
        Log::debug("Testing " + std::to_string(i) + " against " + std::to_string(j));
        if(i % j == 0) {
            Log::debug("fail");
            return true;
        }
    }
    Log::debug("pass");
    return false;
}

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();

    //int factorable = InputWrapper::getInteger("Enter an integer to get all the valid factors");
    int input = Testable<int>::repeatUntilPass(
        Testable<int>(
            []() {
                return InputWrapper::getInteger("Enter an integer to get all the prime numbers before (inclusive):");
            },
            [](int value) {
                return value > 1;
            }
        )
    );
    Log::debug("Number " + std::to_string(input));

    for(int i = 2; i <= input; i++) {
        if(hasFactors(i)) {
            continue;
        }
        Log::info(std::to_string(i));
    }

    return 0;
}