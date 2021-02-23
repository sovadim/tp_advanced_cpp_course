#include <iostream>
#include "loglib/stdoutlogger.h"

namespace log {

void StdoutLogger::log(std::string const& msg, Level const& level) {
    if (level >= level_) {
        std::cout << msg << std::endl;
    }
}

}  // namespace log
