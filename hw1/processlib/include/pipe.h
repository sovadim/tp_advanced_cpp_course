#ifndef PIPE_H
#define PIPE_H

#include <exception>

namespace process {

class Pipe_exception : public std::exception {
    virtual const char *what() const noexcept;
};

class Pipe_close_exception : public std::exception {
    virtual const char *what() const noexcept;
};

class Pipe {
 public:
    Pipe();
    ~Pipe() noexcept;

    size_t read(char *data, size_t len) const;
    size_t write(char *data, size_t len) const;

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

#endif  // PIPE_H
