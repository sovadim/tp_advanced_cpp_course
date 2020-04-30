#ifndef LOGGER_H
#define LOGGER_H

#include <baselogger.h>

namespace log {

class Logger {
 public:
    static Logger& get_instance() {
        static Logger instance;
        return instance;
    }

    BaseLogger get_global_logger();

    void set_global_logger(BaseLogger logger);

 private:
    Logger() {};
    Logger(Logger const&);
    Logger& operator=(Logger const&);
};

}  // namespace log

#endif  // LOGGER_H
