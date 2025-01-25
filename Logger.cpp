//
// Created by anna on 1/20/25.
//

#include "Logger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>




Logger::Logger (const std::string& fileName, const std::string& lvl)
{
    logLevel = getLogLevel(lvl);

    if (!logFile)
    {
        throw std::runtime_error("Could not open log file.");
    }

    logFile.open(fileName, std::ios::app);
}

Logger::~Logger()
{
    logFile.close();
}

void Logger::log(const std::string& lvl, const std::string& message)
{
    std::stringstream ss;
    if (getLogLevel(lvl) < logLevel) return;

    ss<<"["<<getCurrentTime()<<"] "<<"["<<lvl<<"] "<<message<<std::endl;
    logFile<<ss.str();


}

void Logger::setLogLevel(const Level lvl)
{
    logLevel = lvl;
}

std::string Logger::getCurrentTime()
{
    auto currentTime = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(currentTime);


    std::stringstream ss;
    ss << std::put_time(std::localtime(&tt), "%F %T");
    std::string st = ss.str();

    return st;

}

Logger::Level Logger::getLogLevel(const std::string& lvl)
{
    if (lvl == "INFO" || lvl =="Info" || lvl == "info")
            return Level::INFO;
    else if (lvl == "WARNING" || lvl == "Warning" || lvl == "warning")
    {
        return Level::WARNING;
    } else if (lvl == "ERROR" || lvl == "Error" || lvl == "error")
    {
        return Level::ERROR;
    }
}