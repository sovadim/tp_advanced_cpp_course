#pragma once

#include "baselogger.h"

namespace log
{

class StdoutLogger : public BaseLogger
{
public:
    void log(std::string_view msg, Level const &level) override;
};

} // namespace log
