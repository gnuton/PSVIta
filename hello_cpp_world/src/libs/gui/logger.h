#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

class Logger
{
public:
    enum Format { debug, info, warning, error };

private:
    const unsigned short maxBufferSize = 512;

    std::map<Format, const char*> FormatToStr = {
        {Format::debug, "[DEBUG] "},
        {Format::info, "[INFO] "},
        {Format::warning, "[WARN] "},
        {Format::error, "[ERROR] "}
    };
public:
    Logger();
    virtual ~Logger();

    void log(Format f, const std::string& msg);




};

#endif // LOGGER_H
