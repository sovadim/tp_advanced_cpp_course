#ifndef LOGLIB_FILELOGGER_H
#define LOGLIB_FILELOGGER_H

#include <fstream>
#include "loglib/baselogger.h"

namespace log {

class FileLogger : public BaseLogger {
public:
    FileLogger(std::string_view filename, Level const& level);
    void log(std::string_view msg, Level const& level) override;

private:
    std::ofstream ofstream;
};
    
}  // namespace log

#endif  // LOGLIB_FILELOGGER_H
