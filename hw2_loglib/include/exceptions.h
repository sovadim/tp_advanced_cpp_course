#pragma once

#include <stdexcept>

namespace log
{

class BaseLoglibException : public std::runtime_error
{
public:
    BaseLoglibException(const std::string &message) : std::runtime_error{message}
    {
    }

    virtual ~BaseLoglibException() noexcept = default;
};

class FlushException : public BaseLoglibException
{
public:
    FlushException() : BaseLoglibException{"std::flush caused an exception"}
    {
    }
};

} // namespace log
