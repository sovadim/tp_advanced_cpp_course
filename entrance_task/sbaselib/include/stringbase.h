#pragma once

#include <stddef.h>
#include <string>
#include <string_view>
#include <vector>

namespace sbaselib
{

using BaseT = std::vector<std::string>;

class StringBase
{
public:
    StringBase() = default;
    ~StringBase() noexcept = default;

    void push(std::string_view value);
    void insert(std::string_view value, size_t index);
    void change(std::string_view value, size_t index);
    void remove(size_t index);

    const BaseT &getData() const noexcept;

private:
    BaseT dbase_;
};

} // namespace sbaselib
