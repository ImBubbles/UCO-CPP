/**
 * @file a7p1.cpp
 * @brief Caeser Cipher
 * @author Hayden Holmes
 * @date April 2026
 * @version 1.0
 * 
 * Using parameter values, perform a Caeser shift by either decrypting or encrypting
*/
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "logger/Log.h"
#include "logger/LogLevel.h"
#include "util/UtilString.h"
#include "util/UtilVector.h"

const std::string generateAlphabet() { // Uses ascii table to generate (capitalized) alphabet A-Z
    std::string result;
    for(std::size_t i = 65; i <= 90; ++i) {
        result.push_back(i);
    }
    return result;
};

const std::string ALPHABET = generateAlphabet();
const std::string ARGS = "<-d (decrypt)/-e (encrypt)> <key> <file> <output>";

std::string encrypt(std::string key, std::string v) {
    // A = 65
    // Z = 90
    // All characters are 65 > than the index in the alphabet
    std::string result;
    for(const char c : v) {
        if(c >= 'A' && c <= 'Z') {
            result += key.at(c - 65);
        } else {
            result += c;
        }
    }
    return result;
}

std::string decrypt(std::string key, std::string v) {
    std::string result;
    for(const char c : v) {
        if(c >= 'A' && c <= 'Z') {
            // find index in key
            std::size_t index = 0;
            while(key[index] != c && index < key.size()) {
               index++;
            }
            result += ALPHABET[index];
        } else {
            result += c;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {

    //Log::LOG_FILTER = -1; // If commented out, debug messages will not be displayed in console
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    // note: argv[0] is going to be program name

    if(Log::LOG_FILTER == LogLevel::DEBUG) { // avoid iterations if not going to do anything anyways
        for(int i = 0; i < argc; i++) { // Print all args
            Log::debug(UtilString::asUppercase(argv[i]));
        }
        for(const char letter : ALPHABET) { // Print whole alphabet initally
            char str[2];
            str[0] = letter;
            str[1] = '\0';
            Log::log(LogLevel::DEBUG, str, false);
        }
        Log::nl(LogLevel::DEBUG);
    }

    if(argc != 5) {
        Log::error(ARGS);
        Log::debug("Only " + std::to_string(argc) + " args");
        exit(1);
    }

    bool operation = 0;
    // 0 - decrypt
    // 1 - encrypt
    if(std::strcmp(argv[1], "-d") == 0) {
        operation = 0;
    } else if(std::strcmp(argv[1], "-e") == 0) {
        operation = 1;
    } else {
        Log::error(ARGS); // invalid operation
        exit(1);
    }

    std::string strKey = argv[2];
    strKey = UtilString::asUppercase(strKey);
    Log::debug("Key " + strKey);
    // dedupe
    std::vector<char> key;
    for(const char c : strKey) {
        if(!UtilVector::contains(key, c)) {
            key.push_back(c);
        }
    }
    // change alphabet
    std::vector<char> alphabet(ALPHABET.begin(), ALPHABET.end());
    for(const char c : strKey) { // remove key characters from alphabet
        UtilVector::removeElement(alphabet, c);
    }
    if(Log::LOG_FILTER == LogLevel::DEBUG) { // avoid iterating over vector again if not debug
        Log::debug("Deduped key: " + UtilString::vectorAsString(key));
    }
    std::string shift;
    // Add key first
    for(const char c : key) {
        shift += c;
    }
    // Add rest of the alphabet (backwards)
    for (std::size_t i = 0; shift.size() < 26 && i < alphabet.size(); ++i) {
        shift += alphabet[alphabet.size() - 1 - i];
    }
    if(Log::LOG_FILTER == LogLevel::DEBUG) { // avoid iterating over vector if not debug
        Log::debug("Shift: " + shift);
        // test encryption
        Log::debug("Encrypting 'HELLO':");
        std::string encrypted = encrypt(shift, "HELLO");
        Log::debug(encrypted);
        Log::debug("Decrypting '" + encrypted + "':");
        std::string decrypted = decrypt(shift, encrypted);
        Log::debug(decrypted);
    }

    // Read file
    std::vector<std::string> lines;
    std::string inputFileName = argv[3];
    Log::debug("Opening " + inputFileName);
    std::ifstream input(argv[3], std::ios::in); // read file
    if(!input) {
        Log::error("Could not open file " + inputFileName);
        exit(1);
    }
    std::string line;
    while(std::getline(input, line)) {
        lines.push_back(UtilString::asUppercase(line));
        Log::debug("Read line " + line);
    }

    std::vector<std::string> result;

    // Files
    if(operation == 0) { // decrypt
        for(std::string line : lines) {
            result.push_back(decrypt(shift, line));
        }
    } else { // encrypt
        for(std::string line : lines) {
            result.push_back(encrypt(shift, line));
        }
    }

    // Write to output
    std::string outputFileName = argv[4];
    Log::debug("Opening " + outputFileName);
    std::ofstream output(outputFileName, std::ios::out);
    if(!output) {
        Log::error("Error in creating/opening file " + outputFileName);
        exit(1);
    }
    for(std::string line : result) {
        output << line << std::endl;
    }

    std::string opStr = operation ? "encryption" : "decryption";
    Log::info("The " + opStr + " was successful. See results in " + outputFileName);
    
    return 0;
    
}