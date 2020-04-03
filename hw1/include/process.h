#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <exception>
#include "ireadable.h"
#include "iwritable.h"
#include "pipe.h"

namespace process {

class Process_exception: public std::exception {
	virtual const char* what() const noexcept;
};

class Proc_io_exception: public std::exception {
	virtual const char* what() const noexcept;
};

class Process: IWritable, IReadable {
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

	bool is_readable;
};

}  // namespace process

#endif  // PROCESS_H
