#pragma once

#include <span>
#include <stddef.h>

namespace process
{

struct IReadable
{
    virtual ~IReadable() noexcept {};
    virtual size_t read(const std::span<std::byte> buffer) const = 0;
};

} // namespace process
