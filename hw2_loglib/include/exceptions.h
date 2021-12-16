#pragma once

#include <stdexcept>

namespace log
{

class FileNotFoundError : public std::runtime_error
{
public:
    FileNotFoundError(const std::string &path) : std::runtime_error("File <" + path + "> not found")
    {
    }
};

} // namespace log
