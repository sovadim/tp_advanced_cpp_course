#include <unistd.h>
#include "pipe.h"

namespace process {

const char* Pipe_exception::what() const noexcept {
    return "Pipe failed";
}

const char* Pipe_close_exception::what() const noexcept {
    return "Failed to close file descriptor";
}

Pipe::Pipe() {
    if (-1 == ::pipe(fd_)) {
        fd_[0] = -1, fd_[1] = -1;
        throw Pipe_exception();
    }
}

Pipe::~Pipe() noexcept {
    try {close();} catch(std::exception& e) {}
}

size_t Pipe::read(char* data, size_t len) const {
    ssize_t bytes = ::read(fd_[0], data, len);
    if (bytes < 0) throw Pipe_exception();
    return bytes;
}

size_t Pipe::write(char* data, size_t len) const {
    ssize_t bytes = ::write(fd_[1], data, len);
    if (bytes < 0) throw Pipe_exception();
    return bytes;
}

void Pipe::dup_read_fd(int newfd) {
    if (-1 == ::dup2(fd_[0], newfd)) {
        fd_[0] = -1;
        throw Pipe_exception();
    }
}

void Pipe::dup_write_fd(int newfd) {
    if (-1 == ::dup2(fd_[1], newfd)) {
        fd_[1] = -1;
        throw Pipe_exception();
    }
}

void Pipe::close() {
    close_read(), close_write();
}

void Pipe::close_read() {
    if (fd_[0] != -1) {
        if (-1 == ::close(fd_[0])) {
            fd_[0] = -1;
            throw Pipe_close_exception();
        }
    }
}

void Pipe::close_write() {
    if (fd_[1] != -1) {
        if (-1 == ::close(fd_[1])) {
            fd_[1] = -1;
            throw Pipe_close_exception();
        }
    }
}

bool Pipe::is_closed() const {
    return (fd_[0] == -1 || fd_[1] == -1);
}

}  // namespace process
