#pragma once
#include <string>
#include <vector>

namespace UtilString {
    std::string precisionDouble(double db, int precision);
    std::vector<std::string> split(const std::string& str, const char regex);
};