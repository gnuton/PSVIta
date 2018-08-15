#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

#include "utils/Singleton.h"
#include <sstream>
#include <list>
#include <mutex>

#define FORMAT(ITEMS) ((dynamic_cast<std::ostringstream &>(std::ostringstream().seekp( 0, std::ios_base::cur ) << ITEMS )).str())

enum LoggerFormat { debug, info, warning, error };

/**
 * Logger
 * Logger class must be singleton in the application.
 * It works ONLY if the app is built in debug mode (DEBUGNET flag on).
 * 
 * The logged messages are
 * - sent over network through UDP to the host defined into the debugnetip.txt
 * - shown in the screen
 * - (NOT IMPLEMENTED YET) shown in the TTY console if you run the app through Vita3K emulator
 *
 * Basic usage
 * Logger::get_instance().Debug('message')
 */
class Logger: public Singleton<Logger> {
    friend class Singleton<Logger>;
    Logger();

public:
    virtual ~Logger();
    static void TerminateLogger();
    std::string readLogs();

private:
    std::mutex mtx;
    const int maxBufferSize = 128;

    std::map<LoggerFormat, const char*> FormatToStr = {
        {LoggerFormat::debug, "[DEBUG] "},
        {LoggerFormat::info, "[INFO] "},
        {LoggerFormat::warning, "[WARN] "},
        {LoggerFormat::error, "[ERROR] "}
    };
    void Log(LoggerFormat f, const std::string& msg);

    std::list<std::string> logsBuffer;
public:
    void Debug(const std::string& msg)   { this->Log(LoggerFormat::debug, msg); }
    void Info(const std::string& msg)    { this->Log(LoggerFormat::info, msg); }
    void Warning(const std::string& msg) { this->Log(LoggerFormat::warning, msg); }
    void Error(const std::string& msg)   { this->Log(LoggerFormat::error, msg); }
    int logsBufferSizeInLines = 10;
};

#endif // LOGGER_H
