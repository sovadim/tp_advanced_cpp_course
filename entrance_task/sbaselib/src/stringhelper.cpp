#include <iostream>
#include "stringhelper.h"

namespace sbaselib {

std::vector<std::string> parseString(std::string_view value,
                                     std::string_view delimeter = " ") {
    std::vector<std::string> vec;

    size_t position = 0;
    std::string token;
    std::string s = value.data();
    while ((position = s.find(delimeter)) != std::string::npos) {
        token = s.substr(0, position);
        vec.push_back(token);
        std::cout << token << std::endl;
        s.erase(0, position + s.length());
        break;
    }
    return vec;
}

void printStrings(const std::vector<std::string> &base,
                        std::string_view delimeter = " ") {
    for (const auto &a : base) {
        std::cout << a << delimeter;
    }
    std::cout << std::endl;
}

}  // sbaselib
