#pragma once

#include <string>
#include <span>
#include "ireadable.h"
#include "iwritable.h"
#include "pipe.h"

namespace process {

class Process : IWritable, IReadable {
public:
    /* Constructor invokes immediate start of process */
    explicit Process(std::string_view executable);
    ~Process() noexcept;

    static void writeExact(const std::span<void> data) const;
    static void readExact(std::span<void> data) const;

    bool isReadable() const;
    void closeStdin();

    void close();

    /* Child process termination */
    void terminate() const noexcept;

private:
    /* Copying of Process object is prohibited */
    Process(Process const & p);
    Process & operator=(Process const & p);

    Pipe pipe_parent;
    Pipe pipe_child;

    pid_t pid;
};

}  // namespace process
