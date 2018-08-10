#include "logger.h"

#include <debugnet.h>
#include <algorithm>

using namespace std;

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
    string formattedMsg = FormatToStr[f] + msg + '\n';
    formattedMsg.resize(min(512, 512));
    debugNetUDPSend(formattedMsg.c_str());
#endif
}

void Logger::TerminateLogger() {
#ifdef DEBUGNET
    Logger::get_instance()->Log(LoggerFormat::error, "Termingating app...");
    std::exception_ptr p = std::current_exception();
    try {
        std::rethrow_exception(p);
    } catch (const std::exception &e) {
        Logger::get_instance()->Log(LoggerFormat::error, std::string("terminate() because of %s", e.what()));
    }
#endif
}

