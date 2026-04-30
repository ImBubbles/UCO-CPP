#include "logger/Log.h"

int main() {

    Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    // TODO
    

    return 0;
    
}