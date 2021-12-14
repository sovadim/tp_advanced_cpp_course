#include "stderrlogger.h"
#include <iostream>

namespace log
{

void StderrLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cerr << msg << std::endl;
    }
}

} // namespace log
