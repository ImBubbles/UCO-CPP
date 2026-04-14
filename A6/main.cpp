#include "logger/Log.h"
#include "util/UtilString.h"
#include <cstddef>
#include <string>
#include <vector>

int main() {

    Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    int x = 5;
    int* xPtr = &x;
    double y = 5.0;
    double* yPtr = &y;
    std::cout << "sizeof(x): " << sizeof(x) << std::endl;
    std::cout << "sizeof(xPtr): " << sizeof(xPtr) << std::endl;
    std::cout << "sizeof(y): " << sizeof(y) << std::endl;
    std::cout << "sizeof(yPtr): " << sizeof(yPtr) << std::endl;
    std::cout << "goon " << *yPtr << std::endl;

    return 0;
    
}