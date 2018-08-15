#include "Logger.h"

#include <debugnet.h>
#include <algorithm>
#include <string>

Logger::Logger(){
#ifdef DEBUGNET
    debugNetInit(DEBUGNETIP, 18194, 3);
    std::set_terminate(Logger::TerminateLogger);
#endif
}

Logger::~Logger(){
}

void Logger::Log(LoggerFormat f, const std::string& msg){
#ifdef DEBUGNET
    std::lock_guard<std::mutex> lock(mtx);
    std::string formattedMsg = FormatToStr[f] + msg + '\n';
    formattedMsg.resize(std::min(this->maxBufferSize, static_cast<int>(formattedMsg.length())))

    debugNetUDPSend(formattedMsg.c_str());

    logsBuffer.push_back(formattedMsg.c_str());
    if (logsBuffer.size() >= logsBufferSizeInLines)
        logsBuffer.pop_front();
#endif
}

void Logger::TerminateLogger() {
#ifdef DEBUGNET
  Logger::getInstance()->Log(LoggerFormat::error, "Termingating app...");
    std::exception_ptr p = std::current_exception();
    try {
        std::rethrow_exception(p);
    } catch (const std::exception &e) {
      Logger::getInstance()->Log(LoggerFormat::error, std::string("terminate() because of %s", e.what()));
    }
#endif
}

std::string Logger::readLogs() {
    std::lock_guard<std::mutex> lock(mtx);
    std::ostringstream s;
    for (auto line : logsBuffer) {
        s << line << '\n';
    }
    return s.str();
}

