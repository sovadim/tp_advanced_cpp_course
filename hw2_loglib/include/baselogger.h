#pragma once

#include "loglevel.h"
#include <string_view>

namespace log
{

class BaseLogger
{
public:
    BaseLogger() = delete;
    explicit BaseLogger(Level const &level);
    virtual ~BaseLogger() noexcept;

    virtual void debug(std::string_view msg);
    virtual void info(std::string_view msg);
    virtual void warn(std::string_view msg);
    virtual void error(std::string_view msg);

    virtual void setLevel(Level const &level) noexcept;
    virtual Level level() const noexcept;

    void flush();

protected:
    Level m_level;
    virtual void log(std::string_view msg, Level const &level) = 0;
};

} // namespace log
