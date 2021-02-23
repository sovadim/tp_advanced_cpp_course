#pragma once

#include <stddef.h>
#include <span>

namespace process {

struct IReadable {
    virtual ~IReadable() noexcept {};
    virtual size_t read(std::span<void> &buffer) const = 0;
};

}  // namespace process
