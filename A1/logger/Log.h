#pragma once
#include <string>
#include <memory>
#include "LogLevel.h"
#include "loggers/CLogger.h"

class Log {

	// CLASS VARS
public:

	static int LOG_FILTER;

protected:

	static std::unique_ptr<Logger> logger;

	// CLASS METHODS
private:

	static std::string getLevelPrefix(int logLevel);

public:

	Log() = delete;

	static void log(const int& level, const std::string& message);
	static void debug(const std::string &message) {
		log(LogLevel::DEBUG, message);
	}
	static void info(const std::string &message) {
		log(LogLevel::INFO, message);
	}
	static void warning(const std::string &message) {
		log(LogLevel::WARNING, message);
	}
	static void error(const std::string &message) {
		log(LogLevel::ERROR, message);
	}
	static void setLogger(std::unique_ptr<Logger> ref) {
		logger = std::move(ref);
	}
	static void defaultLogger();

};