//
// Created by anna on 1/20/25.
//

#include "Logger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

Logger::Logger (const std::string& fileName, const Level lvl)
{
    logLevel = lvl;

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

void Logger::log(const Level lvl, const std::string& message)
{
    std::stringstream ss;
    if (lvl < logLevel) return;

    ss<<"["<<getCurrentTime()<<"] "<<"["<<getLogLevel(lvl)<<"] "<<message<<std::endl;
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

std::string Logger::getLogLevel(const Level lvl)
{
    switch (lvl)
    {
        case Level::INFO:
            return "INFO";
        case Level::WARNING:
            return "WARNING";
        case Level::ERROR:
            return "ERROR";

    }
}