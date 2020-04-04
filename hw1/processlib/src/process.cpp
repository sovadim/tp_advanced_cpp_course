#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include "process.h"
#include "pipe.h"

namespace process {

const char* Process_exception::what() const noexcept {
    return "Process failed";
}

const char* Proc_io_exception::what() const noexcept {
    return "Read/Write error";
}

Process::Process(const std::string& executable) {
    pid = fork();

    if (-1 == pid) {
        terminate();
        std::cerr << "Bad pid number" << std::endl;
        throw Process_exception();
    }

    if (0 == pid) {
        /* Child process */
        try {
            pipe_parent.close_write();
            pipe_child.close_read();

            pipe_parent.dup_read_fd(fileno(stdin));
            pipe_child.dup_write_fd(fileno(stdout));
        } catch(const std::exception& e) {
            std::cerr << "Child process failed:\n" << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        if (-1 == execl(executable.c_str(), executable.c_str(), NULL)) {
            std::cerr << "Child process failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

Process::~Process() noexcept {
    try {
        close();
        terminate();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

size_t Process::write(const void* data, size_t len) {
    return pipe_parent.write((char*)data, len);
}

void Process::writeExact(const void* data, size_t len) {
    ssize_t byte_couter = 0;
    while (byte_couter != len)
        byte_couter += write(((uint8_t*)data) + byte_couter, len - byte_couter);
}

size_t Process::read(void* data, size_t len) {
    return pipe_child.read((char*)data, len);
}

void Process::readExact(void* data, size_t len) {
    ssize_t byte_couter = 0;
    while (byte_couter < len)
        byte_couter += read(((uint8_t*)data) + byte_couter, len - byte_couter);
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

void Process::terminate() noexcept {
    ::kill(pid, SIGTERM);
    int status;
    if (pid != ::waitpid(pid, &status, 0));
}

}  // namespace process
