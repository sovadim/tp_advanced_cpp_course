#pragma once

#include "ireadable.h"
#include "iwritable.h"

namespace process {

class Pipe : IWritable, IReadable {
public:
    Pipe();
    ~Pipe() noexcept;

    void dupReadFd(int newFd);
    void dupWriteFd(int newFd);

    size_t read(const std::span<std::byte> buffer) const override;
    size_t write(const std::span<const std::byte> buffer) const override;

    void close();

    void closeRead();
    void closeWrite();

    bool isClosed() const;

private:
    std::pair<int, int> m_fd;
};

}  // namespace process
