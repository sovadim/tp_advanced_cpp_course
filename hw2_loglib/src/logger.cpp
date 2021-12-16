#include <logger.h>

namespace log
{

std::shared_ptr<BaseLogger> Logger::getGlobalLogger() const
{
    return m_globalLogger;
}

void Logger::setGlobalLogger(std::unique_ptr<BaseLogger> logger)
{
    m_globalLogger = std::move(logger);
}

} // namespace log
