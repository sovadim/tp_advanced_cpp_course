#include <string>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include "process.h"
#include "pipe.h"

namespace process {

const char* Process_exception::what() const throw() {
    return "Process failed";
}

const char* Proc_io_exception::what() const throw() {
    return "Read/Write error";
}

Process::Process(const std::string& executable) {
    this->executable = executable;

    pipe_parent = new process::Pipe();
    pipe_child  = new process::Pipe();

    readable_state = true;

    pid = fork();

    if (-1 == pid) {
        std::cerr << "Bad pid number" << std::endl;
        terminate();
        throw Process_exception();
    }

    if (0 == pid) {
        /* Child process */
        try {
            pipe_parent->close_stdout();
            pipe_child->close_stdin();

            pipe_parent->dup_stdin(fileno(stdin));
            pipe_child->dup_stdout(fileno(stdout));
        } catch(const std::exception& e) {
            std::cerr << "Child process failed:\n" << e.what() << std::endl;
            _exit(EXIT_FAILURE);
        }

        if (-1 == execl(executable.c_str(), executable.c_str(), NULL)) {
            std::cerr << "Child process failed" << std::endl;
            _exit(EXIT_FAILURE);
        }
    }
}

Process::~Process() noexcept {
    try {
        this->close();
        this->terminate();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

size_t Process::write(const void* data, size_t len) {
    ssize_t bytes = ::write(pipe_parent->get_stdout_fd(), data, len);
    if (bytes < 0) {
        std::cerr << "Process: write error" << std::endl;
        throw Proc_io_exception();
    }
    return bytes;
}

void Process::writeExact(const void* data, size_t len) {

}

size_t Process::read(void* data, size_t len) {
    ssize_t bytes = ::read(pipe_child->get_stdin_fd(), data, len);
    if (bytes < 0) {
        std::cerr << "Process: read error" << std::endl;
        throw Proc_io_exception();
    }
    return bytes;
}

void Process::readExact(void* data, size_t len) {

}

bool Process::isReadable() const {
    return readable_state;
}

void Process::closeStdin() {
    ::close(pipe_child->get_stdin_fd());
    ::close(pipe_parent->get_stdout_fd());
    readable_state = false;
}

void Process::close() {
    ::close(pipe_child->get_stdin_fd());
    ::close(pipe_child->get_stdout_fd());
    ::close(pipe_child->get_stdin_fd());
    ::close(pipe_child->get_stdout_fd());
    readable_state = false;
}

void Process::terminate() {
    this->close();
    if (-1 == kill(pid, SIGTERM))
        std::cerr << "Error, signal not sent" << std::endl;

    int status;
    if (pid != ::waitpid(pid, &status, 0))
        std::cerr << "Error occured when child process terminated" << std::endl;

    if (!WIFSIGNALED(status)) {
        std::cerr << "Child process terminated by error, not by signal" << std::endl;
    }
}

}  // namespace process
