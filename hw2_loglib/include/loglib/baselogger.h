#ifndef BASELOGGER_H
#define BASELOGGER_H

#include <iostream>
#include "loglevel.h"

namespace log {

class BaseLogger {
 public:
   BaseLogger() = delete;
   BaseLogger(Level const& level);
   virtual ~BaseLogger() noexcept;

   virtual void debug(std::string const& msg) const final;
   virtual void info(std::string const& msg) const final;
   virtual void warn(std::string const& msg) const final;
   virtual void error(std::string const& msg) const final;

   virtual void set_level(Level const& level) noexcept final;
   virtual Level level() const noexcept final;

   void flush();

 protected:
   Level level_;
   virtual void log(std::string msg, Level level);
};

}  // namespace log

#endif  // BASELOGGER_H
