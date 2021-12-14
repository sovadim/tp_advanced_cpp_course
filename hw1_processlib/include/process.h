#pragma once

#include "ireadable.h"
#include "iwritable.h"
#include "pipe.h"
#include <span>
#include <string>

namespace process
{

class Process : IWritable, IReadable
{
public:
    /* Constructor invokes immediate start of process */
    explicit Process(std::string_view executable);
    ~Process() noexcept;

    size_t read(const std::span<std::byte> buffer) const override;
    void readExact(std::span<std::byte> buffer) const;

    size_t write(const std::span<const std::byte> buffer) const override;
    void writeExact(std::span<const std::byte> buffer) const;

    bool isReadable() const;
    void closeStdin();

    void close();

    /* Child process termination */
    void terminate() const noexcept;

private:
    Process(Process const &p);
    Process &operator=(Process const &p);

    Pipe m_pipeParent;
    Pipe m_pipeChild;

    pid_t m_pid;
};

} // namespace process
