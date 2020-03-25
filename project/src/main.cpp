#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include "process.h"
#include "pipe.h"

// TODO: remove redundant
#include <unistd.h>
#include <cstdio>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool is_child(pid_t pid);

int main () {
    process::Pipe *pipe_parent;
    process::Pipe *pipe_child;
    
    try {
        pipe_parent = new process::Pipe();
        pipe_child  = new process::Pipe();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // TODO: move in process class
    // TODO: throw exception
    // Create child process
    pid_t pid = fork();
    if (-1 == pid) {
        std::cout << "Bad pid number" << std::endl;
    }

    if (is_child(pid)) {
        /* === Child === */
        try {
            pipe_parent->close_stdout();
            pipe_child->close_stdin();

            pipe_parent->dup_stdin(fileno(stdin));
            pipe_child->dup_stdout(fileno(stdout));
        } catch(const std::exception& e) {
            std::cerr << "Child process failed:\n" << e.what() << std::endl;
            _exit(EXIT_FAILURE);
        }
        
        // TODO: move to process class
        if (-1 == execl("/bin/cat", "/bin/cat", NULL)) {
            std::cerr << "Child process failed" << std::endl;
            _exit(EXIT_FAILURE);
        }
    } else {
        /* === Parent === */

        // TODO: remove buf
        char buf[256];

        std::string buffer;
        while (std::getline(std::cin, buffer)) {
            // TODO: c++ file io
            // TODO: remove buf
            write(pipe_parent->get_stdout_fd(), buffer.c_str(), sizeof(buf));
            printf("sent: %s\n", buffer.c_str());
            read(pipe_child->get_stdin_fd(), buf, sizeof(buf));
            printf("received: %s\n", buf);
        }

        std::cerr << "Eof received, stop" << std::endl;

        /* Child process termination */
        if (-1 == kill(pid, SIGTERM))
            std::cerr << "Error, signal not sent" << std::endl;

        int status;
        if (pid != waitpid(pid, &status, 0))
            std::cerr << "Error occured when child process terminated" << std::endl;

        if (!WIFSIGNALED(status)) {
            std::cerr << "Child process terminated by error, not by signal" << std::endl;
        }

        exit(EXIT_SUCCESS);
    }
}

bool is_child(pid_t pid) {
    return (0 == pid);
}