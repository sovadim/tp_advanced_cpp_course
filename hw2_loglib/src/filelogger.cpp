#include <exceptions.h>
#include <filelogger.h>
#include <iostream>

namespace log
{

void FileLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        ofstream << msg << std::endl;
    }
}

void FileLogger::flush()
{
    ofstream << std::flush;
}

} // namespace log
