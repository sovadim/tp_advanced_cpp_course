#include <iostream>
#include <string.h> // remove
#include <exception>
#include "process.h"
#include "pipe.h"

bool is_child(pid_t pid);

int main(int argc, char** argv) {
    process::Process *proc;

    try {
        proc = new process::Process("/bin/cat");
    } catch (const std::exception& e) {
        std::cerr << "Error in process initialisation" << std::endl;
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // std::string buffer;
    // while (std::getline(std::cin, buffer)) {

    //     // write(pipe_parent->get_stdout_fd(), buffer.c_str(), sizeof(buf));
    //     // printf("sent: %s\n", buffer.c_str());
    //     // read(pipe_child->get_stdin_fd(), buf, sizeof(buf));
    //     // printf("received: %s\n", buf);
    // }

    delete proc;

    return 0;
}
