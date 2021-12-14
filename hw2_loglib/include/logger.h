#pragma once

#include "baselogger.h"
#include <memory>

namespace log
{

class Logger
{
public:
    Logger(Logger const &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;
    Logger &operator=(Logger const &) = delete;

    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    std::shared_ptr<BaseLogger> getGlobalLogger() const;
    void setGlobalLogger(std::unique_ptr<BaseLogger> logger);

private:
    Logger(){};
    std::shared_ptr<BaseLogger> m_globalLogger;
};

} // namespace log
