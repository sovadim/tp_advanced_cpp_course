#ifndef SOLUTION_INCLUDE_STRINGBASE_H_
#define SOLUTION_INCLUDE_STRINGBASE_H_

#include <stddef.h>
#include <string>
#include <iostream>
#include <vector>

namespace sol {

class StringBase {
 public:
    StringBase();

    void push(const std::string &str);
    void insert(const std::string &str, unsigned ind);
    void change(const std::string &str, unsigned ind);
    void remove(unsigned ind);
    const std::vector<std::string> &getData();

 private:
    /* database */
    std::vector<std::string> _data;
};

}  // namespace sol

#endif  // SOLUTION_INCLUDE_STRINGBASE_H_
