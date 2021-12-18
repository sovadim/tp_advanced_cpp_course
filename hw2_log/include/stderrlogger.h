#pragma once

#include <baselogger.h>

namespace log
{

class StderrLogger : public BaseLogger
{
public:
    explicit StderrLogger(Level const &level);
    void log(std::string_view msg, Level const &level) override;
    void flush() override;
};

} // namespace log
