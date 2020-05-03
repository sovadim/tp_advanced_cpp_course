#ifndef STDOUTLOGGER_H
#define STDOUTLOGGER_H

#include "loglib/baselogger.h"

namespace log {

class StdoutLogger : public BaseLogger {
 public:
    using BaseLogger::BaseLogger;
    void log(std::string const& msg, Level const& level) override;
};

}  // namespace log

#endif  // STDOUTLOGGER_H
