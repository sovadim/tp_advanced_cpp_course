#ifndef LOGLIB_STDOUTLOGGER_H
#define LOGLIB_STDOUTLOGGER_H

#include "loglib/baselogger.h"

namespace log {

class StdoutLogger : public BaseLogger {
 public:
    using BaseLogger::BaseLogger;
    void log(std::string_view msg, Level const& level) override;
};

}  // namespace log

#endif  // LOGLIB_STDOUTLOGGER_H
