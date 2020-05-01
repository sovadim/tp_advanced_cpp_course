#include "logger.h"

namespace log {

BaseLogger Logger::get_global_logger() const {
    return global_logger_;
}

void Logger::set_global_logger(BaseLogger const& logger) {
    global_logger_ = logger;
}

}  // namespace log
