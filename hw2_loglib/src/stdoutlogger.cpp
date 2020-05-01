#include <iostream>
#include "stdoutlogger.h"

namespace log {

void StdoutLogger::log(std::string msg, Level level) {
    if (level >= level_) std::cout << msg << std::endl;
}

}  // namespace log
