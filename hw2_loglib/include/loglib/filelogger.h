#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "baselogger.h"

namespace log {

class FileLogger : BaseLogger {
 public:
    FileLogger(std::string filename, Level level);
    void log(std::string msg, Level level) override;

 private:
    std::ofstream ofstream;
};
    
}  // namespace log

#endif  // FILELOGGER_H
