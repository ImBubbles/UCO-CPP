#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class InputWrapper {
protected:
    static std::string ask(const std::string& message) {
        if (!message.empty()) {
            std::cout << message << " ";
        }
        std::string result;
        std::cin >> result;
        //std::cout << std::endl;
        return result;
    }
    static void print(const std::string& message) {
        std::cout << message << std::endl;
    }
public:
    static std::string getString(const std::string& prompt);
    static int getInteger(const std::string& prompt);
    static float getFloat(const std::string& prompt);
    static double getDouble(const std::string& prompt);
};