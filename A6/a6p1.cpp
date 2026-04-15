/**
 * @file a6p1.cpp
 * @brief Get words stored as addresses as to not take up too much space
 * @author Hayden Holmes
 * @date April 2026
 * @version 1.0
 * 
 * Use Tokenizer.h to store new words as pointers and store the document as indexes of corresponding pointers (should be less ram usage)
*/

#include "logger/Log.h" // Logging utility
#include "util/UtilString.h" // String utility
#include <string> // String
#include "util/Tokenizer.h" // Tokenizer

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    Tokenizer tokenizer; // init tokenizer

    //UtilString::split("Apple Banana Orange Apple Grape Banana Kiwi Orange", ' '); <--- Could also use

    std::string words[] = { // Document/list of words
        "Apple",
        "Banana",
        "Orange",
        "Apple",
        "Grape",
        "Banana",
        "Kiwi",
        "Orange",
    };

    for(const std::string& word : words) { // Print all words and their corresponding addresses
        const char* ptr = tokenizer.getElement(tokenizer.tokenize(word.c_str()));
        Log::info("Tokenized " + word + " with address " + UtilString::addrString(ptr));
    }

    return 0;
    
}