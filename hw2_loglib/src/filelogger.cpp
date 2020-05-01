#include <iostream>
#include "filelogger.h"

namespace log {

void FileLogger::log(std::string msg, Level level) {
    if (level >= level_) ofstream << msg << std::endl;
}

}  // namespace log
