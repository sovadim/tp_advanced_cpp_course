#pragma once

#include <vector>
#include <string_view>

/* Split str by delimeter and return data in vector */
std::vector<std::string> parseString(std::string_view str,
                                     std::string_view delimiter);

/* Write data from vector separated by delimeter */
const void printStrings(const std::vector<std::string> &strs,
                        std::string_view &delimiter);

