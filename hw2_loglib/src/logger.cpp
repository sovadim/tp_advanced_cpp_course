#include "loglib/logger.h"

namespace log {

Logger& Logger::get_instance() {
    static Logger instance;
    return instance;
}

BaseLogger Logger::get_global_logger() const {
    return global_logger_;
}

void Logger::set_global_logger(BaseLogger const& logger) {
    global_logger_ = logger;
}


}  // namespace log
