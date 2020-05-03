#include "loglib/logger.h"

namespace log {

std::shared_ptr<BaseLogger> Logger::get_global_logger() const {
    return global_logger_;
}

void Logger::set_global_logger(std::unique_ptr<BaseLogger> logger) {
    global_logger_ = std::move(logger);
}

}  // namespace log
