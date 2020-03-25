#include <unistd.h>
#include <exception>
#include <iostream>
#include "pipe.h"

namespace process
{

const char* Pipe_exception::what() const throw() {
    return "Pipe failed";
}

Pipe::Pipe() {
    if (-1 == pipe(_fd))
        throw Pipe_exception();
}

Pipe::~Pipe() noexcept {
    close(_fd[0]);
    close(_fd[1]);
}

void Pipe::close_stdin() {
    if (-1 == close(_fd[0]))
        throw Pipe_exception();
}

void Pipe::close_stdout() {
    if (-1 == close(_fd[1]))
        throw Pipe_exception();
}

void Pipe::dup_stdin(int newfd) {
    if (-1 == dup2(_fd[0], newfd))
        throw Pipe_exception();
}

void Pipe::dup_stdout(int newfd) {
    if (-1 == dup2(_fd[1], newfd))
        throw Pipe_exception();
}

int Pipe::get_stdin_fd() {
    return _fd[0];
}

int Pipe::get_stdout_fd() {
    return _fd[1];
}

}  // namespace process
