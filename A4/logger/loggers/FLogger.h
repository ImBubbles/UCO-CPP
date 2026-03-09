#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Logger.h"

class FLogger : public Logger {

private:
    std::ofstream file;
public:

    FLogger(const std::string& fileName) : file(fileName, std::ios::out) {}
    void log(const int& level, const std::string& message) override {
        file << getLevelPrefix(level) << " " << message << std::endl;
    }
};