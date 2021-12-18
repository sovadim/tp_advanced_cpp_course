#pragma once

#include <stdexcept>

namespace log
{

class BaseLoglibError : public std::runtime_error
{
public:
    BaseLoglibError(const std::string &message) : std::runtime_error{message}
    {
    }

    virtual ~BaseLoglibError() noexcept = default;
};

class FlushError : public BaseLoglibError
{
public:
    FlushError() : BaseLoglibError{"std::flush caused an exception"}
    {
    }
};

} // namespace log
