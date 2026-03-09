#include "Log.h"
#include "loggers/CLogger.h"
#include <memory>

int Log::LOG_FILTER = 0;

void Log::log(const int& level, const std::string& message) {
	if (level < Log::LOG_FILTER)
		return;
	if (Log::logger == nullptr) {
		return;
	}
	Log::logger->log(level, message);
	//std::cout << getLevelPrefix(level) + " " + message << ANSI::RESET << std::endl;
}

void Log::defaultLogger() {
	Log::setLogger(std::make_unique<CLogger>());
}

std::unique_ptr<Logger> Log::logger = nullptr;