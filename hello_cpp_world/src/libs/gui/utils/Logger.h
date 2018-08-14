#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

#include "utils/Singleton.h"
#include <sstream>

#define FORMAT(ITEMS) ((dynamic_cast<std::ostringstream &>(std::ostringstream().seekp( 0, std::ios_base::cur ) << ITEMS )).str())

enum LoggerFormat { debug, info, warning, error };

class Logger: public Singleton<Logger> {
    friend class Singleton<Logger>;
    Logger();

public:
    virtual ~Logger();
    static void TerminateLogger();

private:
    const unsigned short maxBufferSize = 512;

    std::map<LoggerFormat, const char*> FormatToStr = {
        {LoggerFormat::debug, "[DEBUG] "},
        {LoggerFormat::info, "[INFO] "},
        {LoggerFormat::warning, "[WARN] "},
        {LoggerFormat::error, "[ERROR] "}
    };

    void Log(LoggerFormat f, const std::string& msg);
public:
    void Debug(const std::string& msg)   { this->Log(LoggerFormat::debug, msg); }
    void Info(const std::string& msg)    { this->Log(LoggerFormat::info, msg); }
    void Warning(const std::string& msg) { this->Log(LoggerFormat::warning, msg); }
    void Error(const std::string& msg)   { this->Log(LoggerFormat::error, msg); }
};

#endif // LOGGER_H
