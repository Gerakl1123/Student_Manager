#include "Logger.h"

void Log::write(const std::string& msg)
{

		if (!logFile.is_open()) {
			std::cerr << "[Log error] Файл лога не открыт\n";
			return;
		}

		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		std::tm tm;
		localtime_s(&tm, &t);

		logFile << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] "<< msg << "\n";\

		logFile.flush();
		if (!logFile)
			std::cerr << "[Log error] Не удалось записать в лог\n";
	

}
