#ifndef STDERRLOGGER_H
#define STDERRLOGGER_H

#include "baselogger.h"

namespace log {

class StderrLogger : BaseLogger {
 public:
    StderrLogger();
    void log(std::string msg, Level level) override;
};
    
}  // namespace log

#endif  // STDERRLOGGER_H
