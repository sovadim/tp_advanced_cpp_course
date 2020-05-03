#ifndef STDERRLOGGER_H
#define STDERRLOGGER_H

#include "loglib/baselogger.h"

namespace log {

class StderrLogger : public BaseLogger {
 public:
    using BaseLogger::BaseLogger;
    void log(std::string const& msg, Level const& level) override;
};
    
}  // namespace log

#endif  // STDERRLOGGER_H
