#pragma once

#include <stddef.h>
#include <span>

namespace process {

struct IWritable {
    virtual ~IWritable() noexcept {};
    virtual size_t write(const std::span<const std::byte> buffer) const = 0;
};

}  // namespace process
