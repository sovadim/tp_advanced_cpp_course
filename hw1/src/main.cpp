#include <iostream>
#include <string>
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
        proc->terminate();
        exit(EXIT_FAILURE);
    }

    std::string buffer;

    try {
        while (std::getline(std::cin, buffer)) {
            // TODO: use std::string
            char* void_buffer = new char[buffer.size()];
            // std::string v_buf;
            size_t bytes;

            std::cout << "----------------" << std::endl;
            std::cout << "=== write / read ===" << std::endl;

            bytes = proc->write(buffer.c_str(), buffer.size());
            std::cout << "sent:" << std::endl;
            std::cout << "- data: " << buffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            bytes = proc->read(void_buffer, buffer.size());
            std::cout << "received:" << std::endl;
            std::cout << "- data: " << void_buffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            std::cout << "\n=== writeExact / readExact ===" << std::endl;

            proc->writeExact(buffer.c_str(), buffer.size());
            std::cout << "sent:" << buffer << std::endl;

            proc->readExact(void_buffer, buffer.size());
            std::cout << "received:" << void_buffer << std::endl;

            std::cout << "----------------" << std::endl;

            delete [] void_buffer;
        }
    } catch(std::exception& e) {
        std::cerr << e.what() <<std::endl;
    }

    std::cerr << "Eof received, stop" << std::endl;

    proc->terminate();

    delete proc;

    return 0;
}
