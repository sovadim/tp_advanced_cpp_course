#ifndef GLOBALAPI_H
#define GLOBALAPI_H

#include <string>
#include <memory>
#include "loglib/logger.h"
#include "loglib/baselogger.h"
#include "loglib/stdoutlogger.h"
#include "loglib/stderrlogger.h"
#include "loglib/filelogger.h"

namespace log {

inline void create_file_logger(std::string const& filename,
                               Level level) {
    FileLogger logger(filename, level);
    Logger::get_instance().set_global_logger(
        std::unique_ptr<BaseLogger>(new FileLogger(filename, level)));
}

inline void create_stdout_logger(Level const& level) {
    Logger::get_instance().set_global_logger(
        std::unique_ptr<BaseLogger>(new StdoutLogger(level)));
}

inline void create_stderr_logger(Level level) {
    Logger::get_instance().set_global_logger(
        std::unique_ptr<BaseLogger>(new StderrLogger(level)));
}

inline void debug(std::string const& msg) {
    Logger::get_instance().get_global_logger()->debug(msg);
}

inline void info(std::string const& msg) {
    Logger::get_instance().get_global_logger()->info(msg);
}

inline void warning(std::string const& msg) {
    Logger::get_instance().get_global_logger()->warn(msg);
}

inline void error(std::string const& msg) {
    Logger::get_instance().get_global_logger()->error(msg);
}

}  // namespace log

#endif  // GLOBALAPI_H
