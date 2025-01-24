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

    Logger (const std::string& fileName, Level lvl);
    ~Logger();
    void log (Level lvl, const std::string& msg);
    void setLogLevel(Level lvl);


private:
    std::fstream logFile;
    Level logLevel;

    std::string getCurrentTime();
    std::string getLogLevel(Level lvl);
};



#endif //LOGGER_H
