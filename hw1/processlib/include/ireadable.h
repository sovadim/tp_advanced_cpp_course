#ifndef IREADABLE_H
#define IREADABLE_H

#include <stddef.h>

namespace process {

struct IReadable {
    virtual ~IReadable() noexcept {};
    virtual size_t read(void* data, size_t len) = 0;
};

}  // namespace process

#endif  // IREADABLE_H
