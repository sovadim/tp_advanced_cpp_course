#include "stringbase.h"

namespace sbaselib
{

void StringBase::push(std::string_view value)
{
    dbase_.emplace_back(value);
}

void StringBase::insert(std::string_view value, size_t index)
{
    dbase_.insert(dbase_.begin() + index, std::string(value));
}

void StringBase::change(std::string_view value, size_t index)
{
    dbase_.emplace(dbase_.begin() + index, value);
}

void StringBase::remove(size_t index)
{
    dbase_.erase(dbase_.begin() + index);
}

const BaseT &StringBase::getData() const noexcept
{
    return dbase_;
}

} // namespace sbaselib
