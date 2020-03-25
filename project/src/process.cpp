#include <process.h>
#include <string>
#include <unistd.h>

namespace process {

Process::Process(const std::string& path) {

}

Process::~Process() {}

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

bool Process::isChild() const {

}

void Process::close() {

}

}  // namespace process