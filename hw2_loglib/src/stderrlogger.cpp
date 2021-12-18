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
    std::cerr << std::flush;
}

} // namespace log
