#ifndef LOGLIB_H
#define LOGLIB_H

#include <string>
#include <iostream> // TODO: remove
#include <logger.h>

namespace log {

inline void create_file_logger() {
    // TODO
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

#endif  // LOGLIB_H
