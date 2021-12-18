#include <baselogger.h>

namespace log
{

BaseLogger::BaseLogger(Level const &level) : m_level{level}
{
}

BaseLogger::~BaseLogger() noexcept
{
    try
    {
        flush();
    }
    catch (const std::exception &)
    {
    }
}

void BaseLogger::debug(std::string_view msg)
{
    log(msg, log::Level::DEBUG);
}

void BaseLogger::info(std::string_view msg)
{
    log(msg, log::Level::INFO);
}

void BaseLogger::warn(std::string_view msg)
{
    log(msg, log::Level::WARNING);
}

void BaseLogger::error(std::string_view msg)
{
    log(msg, log::Level::ERROR);
}

void BaseLogger::setLevel(Level const &level) noexcept
{
    m_level = level;
}

Level BaseLogger::level() const noexcept
{
    return m_level;
}

void BaseLogger::flush()
{
}

} // namespace log
