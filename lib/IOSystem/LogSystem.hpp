//
// Created by Romi on 24-7-13.
//

#ifndef LOGSYSTEM_HPP
#define LOGSYSTEM_HPP

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

// fuckU Windows
#ifdef _WIN32
#include <windows.h>
#endif

enum LogLevel {
    Log_INFO,
    Log_WARNING,
    Log_ERROR,
    Log_DEBUG
};

// Get Time
std::string currentDateTime();

class LogSystem {
public:
    explicit LogSystem(LogLevel level);
    ~LogSystem();

    // 重载<<操作符
    template<typename T>
    LogSystem& operator<<(const T& msg) {
        logStream << msg;
        return *this;
    }

    // 重载<<操作符处理日志级别
    LogSystem& operator<<(LogLevel level);

private:
    LogLevel logLevel;
    std::ostringstream logStream;
    static std::string getColorCode(LogLevel level);

#ifdef _WIN32
    HANDLE hConsole;
    static WORD getConsoleColor(LogLevel level);
    static void enableVirtualTerminalProcessing();
#endif
};

// 日志宏定义
#define LOG(level) LogSystem(level)

#endif //LOGSYSTEM_HPP