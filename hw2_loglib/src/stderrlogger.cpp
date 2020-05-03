#include <iostream>
#include "loglib/stderrlogger.h"

namespace log {

void StderrLogger::log(std::string const& msg, Level const& level) {
    if (level >= level_) std::cerr << msg << std::endl;
}

}  // namespace log
