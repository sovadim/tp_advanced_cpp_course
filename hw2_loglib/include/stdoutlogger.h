#pragma once

#include <baselogger.h>

namespace log
{

class StdoutLogger : public BaseLogger
{
public:
    explicit StdoutLogger(Level const &level);
    void log(std::string_view msg, Level const &level) override;
    void flush() override;
};

} // namespace log
