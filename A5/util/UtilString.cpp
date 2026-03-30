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

std::string UtilString::addrString(void* ptr) {
    std::stringstream ss;
    ss << ptr;
    return ss.str();
}
std::string UtilString::padString(int w, const std::string &original, char padding) {
    if(original.length() > w) {
        return original;
    }
    std::stringstream ss;
    int totalPadding = w - original.length();
    int left = ((double) totalPadding / 2) + 0.5;
    int right = totalPadding / 2;
    for(int i = 1; i <= left; i++) {
        ss << padding;
    }
    ss << original;
    for(int i = 1; i <= right; i++) {
        ss << padding;
    }
    return ss.str();
}
std::string UtilString::rightString(int w, const std::string &original, char padding) {
    if(original.length() > w) {
        return original;
    }
    std::stringstream ss;
    int pads = w - original.length();
    for(int i = 1; i <= pads; i++) {
        ss << padding;
    }
    ss << original;
    return ss.str();
}