#include <iostream>
#include "../include/ILogger.h"
#include "../src/LoggerImpl.h"


void test1();

int main() {
    test1();
    return 0;
}


void test1() {
    ILogger* logger = ILogger::createLogger("log.txt");
    logger->log(RC::ALLOCATION_ERROR, ILogger::Level::SEVERE);
    logger->log(RC::IO_ERROR, ILogger::Level::WARNING, __FILE__, __FUNCTION__, __LINE__);

    logger->info(RC::SUCCESS);
    logger->warning(RC::MISMATCHING_DIMENSIONS);
    logger->severe(RC::INFINITY_OVERFLOW);
    logger->info(RC::UNKNOWN, __FILE__, __FUNCTION__, __LINE__);
    logger->severe(RC::MEMORY_INTERSECTION, __FILE__, __FUNCTION__, __LINE__);
    logger->warning(RC::INDEX_OUT_OF_BOUND, __FILE__, __FUNCTION__, __LINE__);

    delete logger;
}