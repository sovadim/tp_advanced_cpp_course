#ifndef PIPE_H
#define PIPE_H

namespace process {

class Pipe {
 public:
    Pipe();
    ~Pipe() noexcept;

    size_t read(char *data, size_t len) const;
    size_t write(const void *data, size_t len) const;

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
