#pragma once
#include "../include/ILogger.h"
#include <fstream>
#include <iostream>

class LoggerImpl : public ILogger {
public:
    LoggerImpl();

    LoggerImpl(std::ofstream* ofs);

    RC log(RC code, Level level, const char* const& srcfile, const char* const& function, int line) override;

    RC log(RC code, Level level) override;

    ~LoggerImpl() override;

private:
    const char* levelToString(Level level);

    const char* rcToString(RC rc);

private:
    std::ofstream* m_ofs;
};