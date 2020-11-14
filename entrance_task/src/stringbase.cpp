#include "stringbase.h"

namespace sol {

StringBase::StringBase() {}

void StringBase::push(const std::string &str) {
    _data.push_back(str);
}

void StringBase::insert(const std::string &str, unsigned ind) {
    _data.insert(_data.begin() + ind, str);
}

void StringBase::change(const std::string &str, unsigned ind) {
    _data.at(ind) = str;
}

void StringBase::remove(unsigned ind) {
    _data.erase(_data.begin() + ind);
}

const std::vector<std::string> &StringBase::getData() {
    return _data;
}

}  // namespace sol
