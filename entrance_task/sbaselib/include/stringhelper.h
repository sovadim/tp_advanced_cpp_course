#pragma once

#include <vector>
#include <string_view>

namespace sbaselib {

/* Split str by delimeter and return data in vector */
std::vector<std::string> parseString(std::string_view value,
                                     std::string_view delimeter);

/* Write data from vector separated by delimeter */
void printStrings(const std::vector<std::string> &base,
                        std::string_view delimeter);

}  // namespace sbaselib
