#include "stdoutlogger.h"
#include <iostream>

namespace log
{

void StdoutLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        std::cout << msg << std::endl;
    }
}

} // namespace log
