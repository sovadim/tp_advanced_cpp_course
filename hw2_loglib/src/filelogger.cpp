#include <exceptions.h>
#include <filelogger.h>
#include <iostream>

namespace log
{

FileLogger::FileLogger(std::string_view /*filename*/, Level const &level) : BaseLogger(level)
{
    // create ofstream
}

void FileLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        ofstream << msg << "\n";
    }
}

void FileLogger::flush()
{
    ofstream << std::flush;
}

} // namespace log
