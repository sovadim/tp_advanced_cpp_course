#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string_view>
#include <string>
#include <stdexcept>
#include "process.h"
#include "pipe.h"

namespace process {

Process::Process(std::string_view executable) {
    m_pid = fork();

    if (m_pid == -1) {
        terminate();
        throw std::runtime_error("Bad pid number");
    }

    if (m_pid == 0) {
        /* Child process */
        try {
            m_pipeParent.closeWrite();
            m_pipeChild.closeRead();
            m_pipeParent.dupReadFd(fileno(stdin));
            m_pipeChild.dupWriteFd(fileno(stdout));
        } catch(const std::exception& e) {
            exit(EXIT_FAILURE);
        }

        if (-1 == execl(executable.data(), executable.data(), NULL)) {
            std::exit(EXIT_FAILURE);
        }
    }
}

Process::~Process() noexcept {
    try {
        close();
        terminate();
    } catch(const std::exception& e) {}
}

size_t Process::write(const std::span<const std::byte> buffer) const {
    return m_pipeParent.write(buffer);
}

void Process::writeExact(const std::span<const std::byte> buffer) const {
    size_t byte_couter = 0;
    while (byte_couter != buffer.size()) {
        byte_couter += write(buffer);
    }
}

size_t Process::read(const std::span<std::byte> buffer) const {
    return m_pipeChild.read(buffer);
}

void Process::readExact(std::span<std::byte> buffer) const {
    size_t byteCouter = 0;
    while (byteCouter < buffer.size()) {
        // shift of span on value of how much read
        byteCouter += read(buffer);
    }
}

bool Process::isReadable() const {
    return !m_pipeParent.isClosed() && !m_pipeChild.isClosed();
}

void Process::closeStdin() {
    m_pipeChild.closeRead();
}

void Process::close() {
    m_pipeChild.close();
}

void Process::terminate() const noexcept {
    ::kill(m_pid, SIGTERM);
    int status;
    ::waitpid(m_pid, &status, 0);
}

}  // namespace process
