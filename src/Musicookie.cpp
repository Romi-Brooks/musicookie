#include <iostream>
#include  "../lib/IOSystem/LogSystem.hpp"

int main() {
    LOG(Log_INFO) << Log_INFO << "This is an info message.";
    LOG(Log_WARNING) << Log_WARNING << "This is a warning message.";
    LOG(Log_ERROR) << Log_ERROR << "This is an error message.";
    LOG(Log_DEBUG) << Log_DEBUG << "This is a debug message.";
    return 0;
}

