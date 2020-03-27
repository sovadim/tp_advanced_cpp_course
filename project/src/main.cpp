#include <iostream>
#include <string> // remove
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
    size_t bytes;

    try {
        while (std::getline(std::cin, buffer)) {
            char* void_buffer = new char[buffer.size()];

            bytes = proc->write(buffer.c_str(), buffer.size());
            std::cout << "sent: " << buffer.c_str() << std::endl;
            std::cout << "bytes sent: " << bytes << std::endl;
            
            bytes = proc->read(void_buffer, buffer.size());
            std::cout << "received: " << void_buffer << std::endl;
            std::cout << "bytes received: " << bytes << std::endl;

            delete [] void_buffer;

            std::cout << "---------------" << std::endl;
        }
    } catch(std::exception& e) {
        std::cerr << e.what() <<std::endl;
    }

    std::cerr << "Eof received, stop" << std::endl;

    proc->terminate();

    delete proc;

    return 0;
}
