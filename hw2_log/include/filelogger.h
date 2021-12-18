#pragma once

#include "baselogger.h"
#include <fstream>

namespace log
{

class FileLogger : public BaseLogger
{
public:
    FileLogger(std::string_view filename, Level const &level);
    void log(std::string_view msg, Level const &level) override;
    void flush() override;

private:
    std::ofstream ofstream_;
};

} // namespace log
