#include "loglib/baselogger.h"

namespace log {

BaseLogger::BaseLogger(Level const& level) : level_(level) {}

BaseLogger::~BaseLogger() {}

void BaseLogger::debug(std::string_view msg) {
    log(msg, log::DEBUG);
}

void BaseLogger::info(std::string_view msg) {
    log(msg, log::INFO);
}

void BaseLogger::warn(std::string_view msg) {
    log(msg, log::WARNING);
}

void BaseLogger::error(std::string_view msg) {
    log(msg, log::ERROR);
}

void BaseLogger::set_level(Level const& level) noexcept {
    level_ = level;
}

Level BaseLogger::level() const noexcept {
    return level_;
}

void BaseLogger::flush() {
    // TODO
}

}  // namespace log
