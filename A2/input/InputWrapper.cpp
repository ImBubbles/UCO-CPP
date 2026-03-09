#include "InputWrapper.h"

std::string InputWrapper::getString(const std::string &prompt) {
    return ask(prompt);
}

int InputWrapper::getInteger(const std::string &prompt) {
    int result;
    while(true) {
        std::string raw = ask(prompt);
        try {
            result = std::stoi(raw);
            break;
        }
        catch (const std::exception& e) {
            std::string message = "Invalid number entered, please enter an integer";
            print(message);
        }
    }
    return result;
}

float InputWrapper::getFloat(const std::string &prompt) {
    float result;
    while(true) {
        std::string raw = ask(prompt);
        try {
            result = std::stof(raw);
            break;
        }
        catch (const std::exception& e) {
            std::string message = "Invalid number entered, please enter an integer";
            print(message);
        }
    }
    return result;
}

double InputWrapper::getDouble(const std::string &prompt) {
    double result;
    while(true) {
        std::string raw = ask(prompt);
        try {
            result = std::stod(raw);
            break;
        }
        catch (const std::exception& e) {
            std::string message = "Invalid number entered, please enter an integer";
            print(message);
        }
    }
    return result;
}