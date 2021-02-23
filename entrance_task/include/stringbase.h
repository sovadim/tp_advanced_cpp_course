#pragma once

#include <stddef.h>
#include <string_view>
#include <vector>

namespace sol {

class StringBase {
public:
    StringBase();
    ~StringBase() noexcept;

    void push(std::string_view str);
    void insert(std::string_view str, size_t ind);
    void change(std::string_view str, size_t ind);
    void remove(size_t ind);
    const std::vector<std::string> &getData();

 private:
    std::vector<std::string> _dbase;
};

}  // namespace sol
