#ifndef GLOBALAPI_H
#define GLOBALAPI_H

#include <string>
#include <iostream> // TODO: remove
#include "logger.h"
#include "filelogger.h"

namespace log {

inline void create_file_logger(std::string const& filename,
                               Level const& level) {
    FileLogger logger(filename, level);
    // Logger::get_instance().set_global_logger(logger);
}

inline void create_stdout_logger() {
    // TODO
}

inline void create_stderr_logger() {
    // TODO
}

// TODO: template to take all elementary types
inline void debug(std::string const& msg) {
    // TODO
    std::cout << msg << std::endl;
}

// TODO: template to take all elementary types
inline void info(std::string const& msg) {
    // TODO
    std::cout << msg << std::endl;
}

// TODO: template to take all elementary types
inline void warning(std::string const& msg) {
    // TODO
    std::cout << msg << std::endl;
}

// TODO: template to take all elementary types
inline void error(std::string const& msg) {
    // TODO
    std::cout << msg << std::endl;
}

}  // namespace log

#endif  // GLOBALAPI_H
