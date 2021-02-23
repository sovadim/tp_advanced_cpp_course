#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include "process.h"
#include "pipe.h"

namespace process {

Process::Process(const std::string& executable) {
    pid = fork();

    if (pid == -1) {
        terminate();
        throw std::runtime_error("Bad pid number");
    }

    if (pid == 0) {
        /* Child process */
        try {
            pipe_parent.close_write();
            pipe_child.close_read();
            pipe_parent.dup_read_fd(fileno(stdin));
            pipe_child.dup_write_fd(fileno(stdout));
        } catch(const std::exception& e) {
            exit(EXIT_FAILURE);
        }

        if (-1 == execl(executable.c_str(), executable.c_str(), NULL)) {
            exit(EXIT_FAILURE);
        }
    }
}

Process::~Process() noexcept {
    try {
        close(), terminate();
    } catch(const std::exception& e) {}
}

size_t Process::write(const std::span<void> buffer) const {
    return pipe_parent.write(data, len);
}

void Process::writeExact(const std::span<void> buffer) const {
    size_t byte_couter = 0;
    while (byte_couter != len) {
        byte_couter += write(((uint8_t*)data) + byte_couter, len - byte_couter);
    }
}

size_t Process::read(std::span<void> &buffer) {
    return pipe_child.read((char*)data, len);
}

void Process::readExact(std::span<void> &buffer) {
    ssize_t byte_couter = 0;
    while (byte_couter < len) {
        byte_couter += read(((uint8_t*)data) + byte_couter, len - byte_couter);
    }
}

bool Process::isReadable() const {
    return !pipe_parent.is_closed() && !pipe_child.is_closed();
}

void Process::closeStdin() {
    pipe_child.close_read();
}

void Process::close() {
    pipe_child.close();
}

void Process::terminate() const noexcept {
    ::kill(pid, SIGTERM);
    int status;
    ::waitpid(pid, &status, 0);
}

}  // namespace process
