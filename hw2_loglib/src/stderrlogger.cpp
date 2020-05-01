#include <iostream>
#include "stderrlogger.h"

namespace log {

void StderrLogger::log(std::string msg, Level level) {
    if (level >= level_) std::cerr << msg << std::endl;
}

}  // namespace log
