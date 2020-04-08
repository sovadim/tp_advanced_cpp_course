#ifndef BASELOGGER_H
#define BASELOGGER_H

#include <iostream>

namespace log
{
    
class BaseLogger {
 public:
    virtual ~BaseLogger();

    void debug(std::string msg);
    void info(std::string msg);
    void warn(std::string msg);
    void error(std::string msg);

    void set_level(/* Level */);
    /* Level */ void level();

    void flush();

 private:
    void log(std::string /*, Level level*/);
};

}  // namespace log

#endif  // BASELOGGER_H
