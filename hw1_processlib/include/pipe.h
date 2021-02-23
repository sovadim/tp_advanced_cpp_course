#pragma once

#include "ireadable.h"
#include "iwritable.h"

namespace process {

class Pipe : IWritable, IReadable {
public:
    Pipe();
    ~Pipe() noexcept;

    void dup_read_fd(int newfd);
    void dup_write_fd(int newfd);

    void close();

    void close_read();
    void close_write();

    bool is_closed() const;

private:
    int fd_[2];
};

}  // namespace process
