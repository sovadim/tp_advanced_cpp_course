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

    std::string buffer;
    void* void_buffer;

    try {
        while (std::getline(std::cin, buffer)) {
            std::cout << "echo: " << buffer.c_str() << std::endl;
            proc->write(buffer.c_str(), buffer.size());
            
            size_t bytes = proc->read(void_buffer, buffer.size());
            // std::cout << "received: " << (char *)void_buffer << std::endl;
            // std::cout << "bytes: " << bytes << std::endl;
        }
    } catch(std::exception& e) {
        std::cerr << e.what() <<std::endl;
    }

    std::cerr << "Eof received, stop" << std::endl;

    proc->terminate();

    delete proc;

    return 0;
}
