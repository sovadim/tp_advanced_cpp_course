#pragma once

#include <span>
#include <stddef.h>

namespace process
{

struct IWritable
{
    virtual ~IWritable() noexcept {};
    virtual size_t write(const std::span<const std::byte> buffer) const = 0;
};

} // namespace process
