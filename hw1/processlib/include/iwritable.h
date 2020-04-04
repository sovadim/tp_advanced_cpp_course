#ifndef IWRITABLE_H
#define IWRITABLE_H

#include <stddef.h>

namespace process {

struct IWritable {
    virtual ~IWritable() noexcept {};
    virtual size_t write(const void* data, size_t len) = 0;
};

}  // namespace process

#endif  // IWRITABLE_H
