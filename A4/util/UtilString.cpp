#include <iomanip>
#include <sstream>
#include <string>
#include "UtilString.h"

std::string UtilString::precisionDouble(double db, int precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << db;
    return oss.str();
}

std::vector<std::string> UtilString::split(const std::string& str, const char regex) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> result;

    while(std::getline(ss, item, regex)) {
        result.push_back(item);
    }
    return result;
}