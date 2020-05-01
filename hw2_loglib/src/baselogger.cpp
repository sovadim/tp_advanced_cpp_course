#include <iostream> // TODO: remove
#include "baselogger.h"

namespace log {

BaseLogger::BaseLogger(Level const& level) : level_(level) {}

void BaseLogger::debug(std::string const& msg) const {
    // TODO
    std::cout << msg << std::endl;
}

void BaseLogger::info(std::string const& msg) const {
    // TODO
    std::cout << msg << std::endl;
}

void BaseLogger::warn(std::string const& msg) const {
    // TODO
    std::cout << msg << std::endl;
}

void BaseLogger::error(std::string const& msg) const {
    // TODO
    std::cout << msg << std::endl;
}

void BaseLogger::set_level(Level const& level) {
    level_ = level;
}

Level BaseLogger::level() const {
    return level_;
}

void BaseLogger::flush() {
    // TODO
}

}  // namespace log
