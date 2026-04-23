/**
 * @file a5p2.cpp
 * @brief Main file for a5p2 assignment
 * @author Hayden Holmes
 * @date March 2026
 * @version 1.0
 * 
 * Print 10 random arrays with numbers 1 - 10 non-repeating
*/

#include "logger/Log.h" // Include logging
#include "util/UtilNumber.h" // Random numbers
#include "util/UtilString.h" // String utility functions
#include <string> // Strings
#include <vector> // Vectors

/**
 * @brief Creates a vector filled with non-repeating random numbers
 * @details Uses a duplicate vector in correct order (1, 2, 3, 4, etc...). Uses an empty vector and fills it by using random indexes from the correct order one whilst removing used entries
 * @param amount size of vector / number to go to (1 - number)
 * @return std::vector result
 */
std::vector<int> permutation(int amount) {
    std::vector<int> filled;
    for(int i = 1; i <= amount; i++) {
        filled.push_back(i);
    }
    std::vector<int> result;
    for(int i = 0; i < amount; i++) {
        int index = UtilNumber::randInt(0, filled.size()-1);
        result.push_back(filled[index]);
        filled.erase(filled.begin() + index);
    }
    return result;
}

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    for(int i = 1; i <= 10; i++) {
        std::cout << UtilString::rightString(20, UtilString::vectorAsString(permutation(10)), ' ') << std::endl;
    }

    return 0;
    
}