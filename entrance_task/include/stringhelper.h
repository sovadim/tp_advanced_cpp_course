#ifndef SOLUTION_INCLUDE_STRINGHELPER_H_
#define SOLUTION_INCLUDE_STRINGHELPER_H_

#include <vector>
#include <string>
#include <iostream>

/* Split str by delimeter and return data in vector */
std::vector<std::string> parseString(const std::string &str,
                                     const std::string &delimiter);

/* Write data from vector separated by delimeter */
const void printStrings(const std::vector<std::string> &strs,
                        const std::string &delimiter);

#endif  // SOLUTION_INCLUDE_STRINGHELPER_H_
