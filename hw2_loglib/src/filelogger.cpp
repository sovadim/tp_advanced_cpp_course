#include <iostream>
#include "loglib/filelogger.h"

namespace log {

void FileLogger::log(std::string const& msg, Level const& level) {
    if (level >= level_) ofstream << msg << std::endl;
}

}  // namespace log
