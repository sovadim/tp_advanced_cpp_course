#ifndef LOGLIB_STDERRLOGGER_H
#define LOGLIB_STDERRLOGGER_H

#include "loglib/baselogger.h"

namespace log {

class StderrLogger : public BaseLogger {
 public:
    using BaseLogger::BaseLogger;
    void log(std::string_view msg, Level const& level) override;
};
    
}  // namespace log

#endif  // LOGLIB_STDERRLOGGER_H
