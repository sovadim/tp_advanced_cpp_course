#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "ireadable.h"
#include "iwritable.h"
#include "pipe.h"

namespace process {

class Process : IWritable, IReadable {
 public:
    /* Constructor invoke immediate start of process */
    explicit Process(const std::string &executable);
    ~Process() noexcept;

    size_t write(const void *data, size_t len) override;
    void writeExact(const void *data, size_t len);
    size_t read(void *data, size_t len) override;
    void readExact(void *data, size_t len);

    bool isReadable() const;
    void closeStdin();

    void close();

    /* Child process termination */
    void terminate() noexcept;

 private:
    /* Copying of Process object is prohibited */
    Process(Process const & p);
    Process & operator=(Process const & p);

    Pipe pipe_parent;
    Pipe pipe_child;

    pid_t pid;
};

}  // namespace process

#endif  // PROCESS_H
