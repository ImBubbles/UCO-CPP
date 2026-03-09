/**
 * @file a3p1.cpp
 * @brief Assignment 3 Part 1
 * @author Hayden Holmes
 * @date February 2026
 * @version 1.0
 * 
 * Lists all factors
*/

#include "logger/Log.h"
#include "input/InputWrapper.h"
#include "util/Testable.h"

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();

    int factorable = Testable<int>::repeatUntilPass(
        Testable<int>(
            []() {
                return InputWrapper::getInteger("Enter an integer to get all the valid factors:");
            },
            [](int value) {
                return value > 0;
            }
        )
    );
    Log::debug("Number " + std::to_string(factorable));

    for(int i = 1; i <= factorable; i++) {
        if(factorable % i != 0) {
            continue;
        }
        Log::info(std::to_string(i) + " is a factor of " + std::to_string(factorable));
    }

    return 0;
}