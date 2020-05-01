#ifndef LOGGER_H
#define LOGGER_H

#include <baselogger.h>

namespace log {

class Logger {
 public:
    Logger(Logger const&) = delete;
    Logger(Logger &&) = delete;
    Logger& operator=(Logger &&) = delete;
    Logger& operator=(Logger const&) = delete;

    static Logger& get_instance();
    BaseLogger get_global_logger() const;
    void set_global_logger(BaseLogger const& logger);

 private:
    Logger() = default;
    BaseLogger global_logger_;
};

}  // namespace log

#endif  // LOGGER_H
