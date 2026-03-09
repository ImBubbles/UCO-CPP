#include <iomanip>
#include <sstream>
#include "UtilString.h"

std::string UtilString::precisionDouble(double db, int precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << db;
    return oss.str();
}