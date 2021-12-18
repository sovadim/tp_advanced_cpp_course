#include <exceptions.h>
#include <filelogger.h>
#include <iostream>

namespace log
{

FileLogger::FileLogger(std::string_view filename, Level const &level)
    : BaseLogger{level}, ofstream_{filename.data()}
{
}

void FileLogger::log(std::string_view msg, Level const &level)
{
    if (level >= m_level)
    {
        ofstream_ << msg << "\n";
    }
}

void FileLogger::flush()
{
    try
    {
        ofstream_ << std::flush;
    }
    catch (const std::exception &e)
    {
        throw FlushException();
    }
}

} // namespace log
