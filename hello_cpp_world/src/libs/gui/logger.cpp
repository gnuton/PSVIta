#include "logger.h"
#include <debugnet.h>
#include <algorithm>

using namespace std;

Logger::Logger(){
#ifdef DEBUGNET
    debugNetInit(DEBUGNETIP, 18194, 3);
#endif
}

Logger::~Logger(){
}

void Logger::log(LoggerFormat f, const std::string& msg){
#ifdef DEBUGNET
    string formattedMsg = FormatToStr[f] + msg + '\n';
    formattedMsg.resize(min(512, 512));
    debugNetUDPSend(formattedMsg.c_str());
#endif
}
