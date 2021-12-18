#include <exceptions.h>
#include <iostream>
#include <stderrlogger.h>

namespace log
{

StderrLogger::StderrLogger(Level const &level) : BaseLogger(level)
{
}

void StderrLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cerr << msg << "\n";
    }
}

void StderrLogger::flush()
{
    try
    {
        std::cerr << std::flush;
    }
    catch (const std::exception &e)
    {
        throw FlushException();
    }
}

} // namespace log
