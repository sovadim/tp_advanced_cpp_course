#include <logger.h>

namespace log
{

std::shared_ptr<BaseLogger> Logger::getGlobalLogger() const noexcept
{
    return m_globalLogger;
}

void Logger::setGlobalLogger(std::unique_ptr<BaseLogger> logger) noexcept
{
    m_globalLogger = std::move(logger);
}

} // namespace log
