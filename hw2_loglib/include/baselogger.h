#ifndef LOGLIB_BASELOGGER_H
#define LOGLIB_BASELOGGER_H

#include <iostream>
#include "loglib/loglevel.h"

namespace log {

class BaseLogger {
public:
    BaseLogger() = delete;
    explicit BaseLogger(Level const& level);
    virtual ~BaseLogger() noexcept;

    virtual void debug(std::string_view msg) final;
    virtual void info(std::string_view msg) final;
    virtual void warn(std::string_view msg) final;
    virtual void error(std::string_view msg) final;

    virtual void set_level(Level const& level) noexcept final;
    virtual Level level() const noexcept final;

    void flush();

protected:
    Level level_;
    virtual void log(std::string_view msg, Level const& level) = 0;
};

}  // namespace log

#endif  // LOGLIB_BASELOGGER_H
