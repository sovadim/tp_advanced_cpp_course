#include "pipe.h"
#include "process.h"
#include <exception>
#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::unique_ptr<process::Process> process;

    try
    {
        process = std::make_unique<process::Process>("/bin/cat");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in process initialisation" << std::endl;
        std::cerr << e.what() << std::endl;
        process->terminate();
        return 1;
    }

    std::string buffer;

    try
    {
        while (std::getline(std::cin, buffer))
        {
            std::string voidBuffer;
            voidBuffer.resize(buffer.size());
            size_t bytes;

            std::cout << "----------------" << std::endl;
            std::cout << "=== write / read ===" << std::endl;

            bytes = process->write(
                {reinterpret_cast<const std::byte *>(buffer.c_str()), buffer.size()});

            std::cout << "\nsent:" << std::endl;
            std::cout << "- data: " << buffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            bytes =
                process->read({reinterpret_cast<std::byte *>(voidBuffer.data()), buffer.size()});
            std::cout << "received:" << std::endl;
            std::cout << "- data: " << voidBuffer << std::endl;
            std::cout << "- bytes: " << bytes << std::endl;

            std::cout << "\n=== writeExact / readExact ===" << std::endl;

            process->writeExact(
                {reinterpret_cast<const std::byte *>(buffer.c_str()), buffer.size()});
            std::cout << "\nsent:" << buffer << std::endl;

            process->readExact({reinterpret_cast<std::byte *>(voidBuffer.data()), buffer.size()});
            std::cout << "received:" << voidBuffer << std::endl;

            std::cout << "----------------" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cerr << "Eof received, stop" << std::endl;
    return 0;
}
