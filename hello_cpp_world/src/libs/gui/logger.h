#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include "singleton.h"

enum LoggerFormat { debug, info, warning, error };
class Logger: public Singleton<Logger> {
    friend class Singleton<Logger>;
    Logger();
public:
    virtual ~Logger();

private:
    const unsigned short maxBufferSize = 512;

    std::map<LoggerFormat, const char*> FormatToStr = {
        {LoggerFormat::debug, "[DEBUG] "},
        {LoggerFormat::info, "[INFO] "},
        {LoggerFormat::warning, "[WARN] "},
        {LoggerFormat::error, "[ERROR] "}
    };


public:
    void log(LoggerFormat f, const std::string& msg);
};

#endif // LOGGER_H
