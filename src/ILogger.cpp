#include "../include/ILogger.h"
#include "LoggerImpl.h"

ILogger* ILogger::createLogger() { 
    return new (std::nothrow) LoggerImpl();
}

ILogger* ILogger::createLogger(const char* const& filename, bool overwrite) {
    std::ofstream* ofs;
    if (overwrite) {
        ofs = new std::ofstream(filename, std::ios::out);
    } else {
        ofs = new std::ofstream(filename, std::ios::app);
    }
    return new (std::nothrow) LoggerImpl(ofs);
}

ILogger::~ILogger() {}