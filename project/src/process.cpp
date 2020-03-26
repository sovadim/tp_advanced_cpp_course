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

Process::Process(const std::string& executable) {
    this->executable = executable;

    pipe_parent = new process::Pipe();
    pipe_child  = new process::Pipe();

    pid = fork();
    if (-1 == pid)
        std::cout << "Bad pid number" << std::endl;

    if (0 == pid) {
        std::cout << "Child" << std::endl;
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
    } else {
        std::cout << "Parent" << std::endl;

        char buf[256];

        std::string buffer;
        while (std::getline(std::cin, buffer)) {
            // TODO: c++ file io
            // TODO: remove buf
            ::write(pipe_parent->get_stdout_fd(), buffer.c_str(), sizeof(buf));
            printf("sent: %s\n", buffer.c_str());
            ::read(pipe_child->get_stdin_fd(), buf, sizeof(buf));
            printf("received: %s\n", buf);
        }

        std::cerr << "Eof received, stop" << std::endl;   
    }
}

Process::~Process() noexcept {
    try {
        terminate();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

size_t Process::write(const void* data, size_t len) {

    return 0;
}

void Process::writeExact(const void* data, size_t len) {

}

size_t Process::read(void* data, size_t len) {
    return 0;
}

void Process::readExact(void* data, size_t len) {

}

bool Process::isReadable() const {
    return 0;
}

void Process::closeStdin() {

}

void Process::close() {

}

void Process::terminate() {
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