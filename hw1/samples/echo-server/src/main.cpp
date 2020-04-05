#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include "process.h"
#include "pipe.h"

int main(int argc, char** argv) {
    std::unique_ptr<process::Process> process;

    try {
        process = std::make_unique<process::Process>("/bin/cat");// = new process::Process("/bin/cat");
    } catch (const std::exception& e) {
        std::cerr << "Error in process initialisation" << std::endl;
        std::cerr << e.what() << std::endl;
        process->terminate();
        return 1;
    }

    std::string buffer;

    try {
        while (std::getline(std::cin, buffer)) {
            std::string void_buffer;
            void_buffer.resize(buffer.size());
            size_t bytes;

            std::cout << "----------------" << std::endl;
            std::cout << "=== write / read ===" << std::endl;

            bytes = process->write(buffer.c_str(), buffer.size());
            std::cout << "sent:" << std::endl;
            std::cout << "- data: " << buffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            bytes = process->read((void *)void_buffer.data(), buffer.size());
            std::cout << "received:" << std::endl;
            std::cout << "- data: " << void_buffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            std::cout << "\n=== writeExact / readExact ===" << std::endl;

            process->writeExact(buffer.c_str(), buffer.size());
            std::cout << "sent:" << buffer << std::endl;

            process->readExact(&void_buffer[0], buffer.size());
            std::cout << "received:" << void_buffer << std::endl;

            std::cout << "----------------" << std::endl;
        }
    } catch(std::exception& e) {
        std::cerr << e.what() <<std::endl;
    }

    std::cerr << "Eof received, stop" << std::endl;
    return 0;
}
