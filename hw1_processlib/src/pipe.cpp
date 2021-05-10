#include <unistd.h>
#include <stdexcept>
#include "pipe.h"

namespace process {

Pipe::Pipe() {
    // TODO: fix
    int tmp[2];
    tmp[0] = m_fd.first;
    tmp[1] = m_fd.second;
    if (::pipe(tmp) == -1) {
        m_fd.first = -1;
        m_fd.second = -1;
        throw std::runtime_error("Pipe failed");
    }
}

Pipe::~Pipe() noexcept {
    try {
        close();
    } catch(const std::exception& e) {
        // TODO: write error to stderr
    }
}

size_t Pipe::read(std::span<std::byte> buffer) const {
    ssize_t bytes = ::read(m_fd.first, buffer.data(), buffer.size());
    if (bytes < 0) {
        throw std::runtime_error("Pipe failed - read error");
    }
    return bytes;
}

size_t Pipe::write(const std::span<const std::byte> buffer) const {
    ssize_t bytes = ::write(m_fd.second, buffer.data(), buffer.size());
    if (bytes < 0) {
        throw std::runtime_error("Pipe failed - write error");
    }
    return bytes;
}

void Pipe::dupReadFd(int newfd) {
    if (::dup2(m_fd.first, newfd) == -1) {
        m_fd.first = -1;
        throw std::runtime_error("Pipe failed - dup error");
    }
}

void Pipe::dupWriteFd(int newfd) {
    if (::dup2(m_fd.second, newfd) == -1) {
        m_fd.second = -1;
        throw std::runtime_error("Pipe failed - dup error");
    }
}

void Pipe::close() {
    closeRead();
    closeWrite();
}

void Pipe::closeRead() {
    if (m_fd.first != -1) {
        if (::close(m_fd.first) == -1) {
            m_fd.first = -1;
            throw std::runtime_error("Pipe failed - read fd not closed");
        }
    }
}

void Pipe::closeWrite() {
    if (m_fd.second != -1) {
        if (::close(m_fd.second) == -1) {
            m_fd.second = -1;
            throw std::runtime_error("Pipe failed - write fd not closed");
        }
    }
}

bool Pipe::isClosed() const {
    return (m_fd.first == -1 || m_fd.second == -1);
}

}  // namespace process
