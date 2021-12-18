#pragma once

#include "baselogger.h"
#include "filelogger.h"
#include "logger.h"
#include "stderrlogger.h"
#include "stdoutlogger.h"
#include <memory>
#include <string_view>

namespace log
{

inline void createFileLogger(std::string_view filename, Level level)
{
    FileLogger logger(filename, level);
    Logger::getInstance().setGlobalLogger(std::make_unique<FileLogger>(filename, level));
}

inline void createStdoutLogger(Level const &level)
{
    Logger::getInstance().setGlobalLogger(std::make_unique<StdoutLogger>(level));
}

inline void createStderrLogger(Level const &level)
{
    Logger::getInstance().setGlobalLogger(std::make_unique<StderrLogger>(level));
}

inline void debug(std::string_view msg)
{
    Logger::getInstance().getGlobalLogger()->debug(msg);
}

inline void info(std::string_view msg)
{
    Logger::getInstance().getGlobalLogger()->info(msg);
}

inline void warning(std::string_view msg)
{
    Logger::getInstance().getGlobalLogger()->warn(msg);
}

inline void error(std::string_view msg)
{
    Logger::getInstance().getGlobalLogger()->error(msg);
}

inline void flush()
{
    Logger::getInstance().getGlobalLogger()->flush();
}

} // namespace log
