#include <iostream>
#include "stringhelper.h"

std::vector<std::string> parseString(std::string_view str,
                                     std::string_view delimiter = " ") {
    std::vector<std::string> vec;

    size_t position = 0;
    std::string token;
    std::string s = str;
    while ((position = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, position);
        vec.push_back(token);
        std::cout << token << std::endl;
        s.erase(0, position + s.length());
        break;
    }
    return vec;
}

const void printStrings(const std::vector<std::string> &strs,
                        std::string_view delimeter = " ") {
    for (auto &a : strs) {
        std::cout << a << delimeter;
    }
    std::cout << std::endl;
}
