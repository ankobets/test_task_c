//
// Created by anna on 1/20/25.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>


class Logger
{
public:
    enum class Level
    {
        INFO, WARNING, ERROR
    };

    Logger (const std::string& fileName, const std::string& lvl);
    ~Logger();
    void log (const std::string& lvl, const std::string& msg);
    void setLogLevel(const std::string& lvl);


private:
    std::fstream logFile;
    Level logLevel;

    std::string getCurrentTime();
    Level getLogLevel(const std::string& lvl);
};


#endif //LOGGER_H
