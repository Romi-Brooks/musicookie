//
// Created by Romi on 24-7-13.
//
#include "../../lib/IOSystem/LogSystem.hpp"

// 获取当前时间的字符串表示
std::string currentDateTime() {
    time_t now = time(nullptr);
    struct tm tstruct{};
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y-%m-%d][%X]", &tstruct);
    return buf;
}

// LogSystem 类构造函数
LogSystem::LogSystem(LogLevel level) : logLevel(level) {
#ifdef _WIN32
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    enableVirtualTerminalProcessing();
#endif
}

// LogSystem 类析构函数
LogSystem::~LogSystem() {
#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, 7);  // Reset to default color
#else
    std::cout << "\033[0m";  // Reset color at the end
#endif
    std::cout << logStream.str() << std::endl;
}

// 重载<<操作符处理日志级别
LogSystem& LogSystem::operator<<(LogLevel level) {
#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, getConsoleColor(level));
#else
    logStream << getColorCode(level);
#endif

    switch(level) {
        case Log_INFO:
            logStream << "\033[32m""[INFO]";
        break;
        case Log_WARNING:
            logStream << "\033[33m""[WARNING]";
        break;
        case Log_ERROR:
            logStream << "\033[31m""[ERROR]";
        break;
        case Log_DEBUG:
            logStream << "\033[34m""[DEBUG]";
        break;
    }
    logStream << currentDateTime() << "\033[0m"":";
    return *this;
}

// 获取对应日志级别的颜色代码（ANSI转义码）
std::string LogSystem::getColorCode(LogLevel level) {
    switch(level) {
        case Log_INFO:
            return "\033[32m";  // 绿色
        case Log_WARNING:
            return "\033[33m";  // 黄色
        case Log_ERROR:
            return "\033[31m";  // 红色
        case Log_DEBUG:
            return "\033[34m";  // 蓝色
        default:
            return "\033[0m";   // 重置
    }
}

#ifdef _WIN32
// 获取对应日志级别的控制台颜色代码（Windows API）
// Fuck U Windows
WORD LogSystem::getConsoleColor(LogLevel level) {
    switch(level) {
        case Log_INFO:
            return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Log_WARNING:
            return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case Log_ERROR:
            return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case Log_DEBUG:
            return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        default:
            return 7;  // Default console color
    }
}
// 启用Windows终端的ANSI转义码支持
// Fuck U Windows
void LogSystem::enableVirtualTerminalProcessing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif