#pragma once
#include <string>
#include "../LogLevel.h"
class Logger {

protected:
    Logger() = default;
public:
    virtual void log(const int& level, const std::string& message) = 0;
protected:
    virtual const std::string getLevelPrefix(const int logLevel) {
        switch (logLevel) {
            case DEBUG:
                return "[DEBUG]";
            case WARNING:
                return "[WARNING]";
            case ERROR:
                return "[ERROR]";
            default:
                return "[INFO]";
        }
    }
};