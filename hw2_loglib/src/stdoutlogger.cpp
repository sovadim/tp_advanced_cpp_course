#include <iostream>
#include <stdoutlogger.h>

namespace log
{

void StdoutLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cout << msg << std::endl;
    }
}

void StdoutLogger::flush()
{
    std::cout << std::flush;
}

} // namespace log
