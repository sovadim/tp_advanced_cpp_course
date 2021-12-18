#include <iostream>
#include <stdoutlogger.h>

namespace log
{

StdoutLogger::StdoutLogger(Level const &level) : BaseLogger(level)
{
}

void StdoutLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cout << msg << "\n";
    }
}

void StdoutLogger::flush()
{
    std::cout << std::flush;
}

} // namespace log
