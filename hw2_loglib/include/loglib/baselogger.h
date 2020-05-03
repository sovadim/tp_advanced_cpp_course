#ifndef BASELOGGER_H
#define BASELOGGER_H

#include <iostream>
#include "loglib/loglevel.h"

namespace log {

class BaseLogger {
 public:
    BaseLogger() = delete;
    explicit BaseLogger(Level const& level);
    virtual ~BaseLogger() noexcept;

    virtual void debug(std::string const& msg) final;
    virtual void info(std::string const& msg) final;
    virtual void warn(std::string const& msg) final;
    virtual void error(std::string const& msg) final;

    virtual void set_level(Level const& level) noexcept final;
    virtual Level level() const noexcept final;

    void flush();

 protected:
    Level level_;
    virtual void log(std::string const& msg, Level const& level) = 0;
};

}  // namespace log

#endif  // BASELOGGER_H
