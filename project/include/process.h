#ifndef PROJECT_INCLUDE_PROCESS_H_
#define PROJECT_INCLUDE_PROCESS_H_

#include <string>
#include <exception>
#include "pipe.h"

namespace process
{

class Process_exception: public std::exception {
   virtual const char* what() const throw();
};

class Proc_io_exception: public std::exception {
   virtual const char* what() const throw();
};

class Process {
 public:
   /* Constructor invoke immediate start of process */
   explicit Process(const std::string& executable);
   ~Process() noexcept;

   size_t write(const void* data, size_t len);
   void writeExact(const void* data, size_t len);
   size_t read(void* data, size_t len);
   void readExact(void* data, size_t len);

   bool isReadable() const;
   void closeStdin();

   void close();

   /* Child process termination */
   void terminate();

 private:
   Pipe *pipe_parent;
   Pipe *pipe_child;
   
   pid_t pid;

   bool readable_state;

   /* Path to program to execute */
   std::string executable;
};

}  // namespace process

#endif  // PROJECT_INCLUDE_PROCESS_H_
