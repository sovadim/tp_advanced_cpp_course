#ifndef PIPE_H
#define PIPE_H

#include <exception>

namespace process
{

class Pipe_exception: public std::exception {
   virtual const char* what() const throw();
};

class Pipe {
 public:
   Pipe();
   ~Pipe() noexcept;

   int get_stdin_fd();
   int get_stdout_fd();

   void dup_stdin(int newfd);
   void dup_stdout(int newfd);

   void close_stdin();
   void close_stdout();

 private:
   int _fd[2];
};

}  // namespace process

#endif  // PIPE_H
