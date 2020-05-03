#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "loglib/baselogger.h"

namespace log {

class FileLogger : public BaseLogger {
 public:
    FileLogger(std::string filename, Level const& level);
    void log(std::string const& msg, Level const& level) override;

 private:
    std::ofstream ofstream;
};
    
}  // namespace log

#endif  // FILELOGGER_H
