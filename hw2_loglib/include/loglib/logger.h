#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include "loglib/baselogger.h"

namespace log {

class Logger {
 public:
    Logger(Logger const&) = delete;
    Logger(Logger &&) = delete;
    Logger& operator=(Logger &&) = delete;
    Logger& operator=(Logger const&) = delete;

    static Logger& get_instance() {
        static Logger instance;
        return instance;
    }
    
    std::shared_ptr<BaseLogger> get_global_logger() const;
    void set_global_logger(std::unique_ptr<BaseLogger> logger);

 private:
    Logger() {};
    std::shared_ptr<BaseLogger> global_logger_;
};

}  // namespace log

#endif  // LOGGER_H
