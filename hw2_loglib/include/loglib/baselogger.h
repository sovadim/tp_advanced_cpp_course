#ifndef BASELOGGER_H
#define BASELOGGER_H

#include <iostream>

namespace log {

// TODO: redo to enum class
enum Level {
   DEBUG,
   INFO,
   WARNING,
   ERROR
};

class BaseLogger {
 public:
    virtual ~BaseLogger();

    void debug(std::string& msg);
    void info(std::string& msg);
    void warn(std::string& msg);
    void error(std::string& msg);

    void set_level(Level level);
    Level level();

    void flush();

 private:
    Level level_;
    void log(std::string msg, Level level);
};

}  // namespace log

#endif  // BASELOGGER_H
