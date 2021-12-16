#include <iostream>
#include <stderrlogger.h>

namespace log
{

void StderrLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cerr << msg << std::endl;
    }
}

void StderrLogger::flush()
{
    std::cerr << std::flush;
}

} // namespace log
