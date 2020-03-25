#ifndef PROJECT_INCLUDE_PROCESS_H_
#define PROJECT_INCLUDE_PROCESS_H_

#include <string>

namespace process
{

class Process {
 public:
    explicit Process(const std::string& path);
    ~Process();

    size_t write(const void* data, size_t len);
    void writeExact(const void* data, size_t len);
    size_t read(void* data, size_t len);
    void readExact(void* data, size_t len);

    bool isReadable() const;
    void closeStdin();

    bool isChild() const;

    void close();

 private:
    pid_t pid;
};

}  // namespace process

#endif  // PROJECT_INCLUDE_PROCESS_H_
