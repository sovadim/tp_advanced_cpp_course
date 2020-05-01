#ifndef STDOUTLOGGER_H
#define STDOUTLOGGER_H

#include "baselogger.h"

namespace log {

class StdoutLogger : BaseLogger {
 public:
    StdoutLogger(Level level);
    void log(std::string msg, Level level) override;
};

}  // namespace log

#endif  // STDOUTLOGGER_H
