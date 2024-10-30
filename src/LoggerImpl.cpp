#include "LoggerImpl.h"


LoggerImpl::LoggerImpl() : m_ofs() {}

LoggerImpl::LoggerImpl(std::ofstream* ofs) : m_ofs(ofs) {}

RC LoggerImpl::log(RC code, Level level, const char* const& srcfile, const char* const& function,
                   int line) {
    if (m_ofs->is_open()) {
        *m_ofs << srcfile << " " << function << " " << line << " " << levelToString(level) << " "
               << rcToString(code) << std::endl;
    } else {
        std::cout << srcfile << " " << function << " " << line << " " << levelToString(level) << " "
                  << rcToString(code) << std::endl;
    }
    return code;
}

RC LoggerImpl::log(RC code, Level level) {
    if (m_ofs->is_open())
        *m_ofs << levelToString(level) << ": " << rcToString(code) << std::endl;
    else
        std::cout << levelToString(level) << ": " << rcToString(code) << std::endl;
    return code;
}

LoggerImpl::~LoggerImpl() {
    if (m_ofs->is_open())
        m_ofs->close();
    delete m_ofs;
}

const char* LoggerImpl::levelToString(Level level) {
    switch (level) {
    case ILogger::Level::SEVERE:
        return "Severe";
    case ILogger::Level::WARNING:
        return "Warning";
    case ILogger::Level::INFO:
        return "INFO";
    default:
        return "";
    }
}

const char* LoggerImpl::rcToString(RC rc) {
    switch (rc) {
    case RC::AMOUNT:
        return "Amount";
    case RC::UNKNOWN:
        return "Unknown error";
    case RC::SUCCESS:
        return "Success";
    case RC::INVALID_ARGUMENT:
        return "Argument is invalid";
    case RC::MISMATCHING_DIMENSIONS:
        return "Mismatching dimension";
    case RC::INDEX_OUT_OF_BOUND:
        return "Index is out of bound";
    case RC::INFINITY_OVERFLOW:
        return "Number is greater than infinity";
    case RC::NOT_NUMBER:
        return "Not a number";
    case RC::ALLOCATION_ERROR:
        return "Couldn't allocate new memory";
    case RC::NULLPTR_ERROR:
        return "Received nullptr";
    case RC::FILE_NOT_FOUND:
        return "Couldn't find file with corresponding name";
    case RC::VECTOR_NOT_FOUND:
        return "Couldn't find vector instance in ISet method";
    case RC::IO_ERROR:
        return "Couldn't write/read to/from file";
    case RC::MEMORY_INTERSECTION:
        return "Found intersecting memory while copying instance";
    case RC::SOURCE_SET_DESTROYED:
        return "Iterator trying to work with dead set";
    case RC::SOURCE_COMPACT_DESTROYED:
        return "Iterator trying to work with dead compact";
    case RC::SOURCE_SET_EMPTY:
        return "Iterator trying to move to the begin/end of empty set";
    case RC::VECTOR_ALREADY_EXIST:
        return "Vector has already existed";
    case RC::SET_INDEX_OVERFLOW:
        return "Index of set if overflow";
    case RC::NO_ARGS_SET:
        return "No arguments set for problem to evaluate or for solver to solve";
    case RC::NO_PARAMS_SET:
        return "No params set for problem to evaluate or for solver to solve";
    case RC::NO_PROBLEM_SET:
        return "No problem set for solver to solve";
    default:
        return "";
    }
}