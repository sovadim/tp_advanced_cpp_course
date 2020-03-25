#ifndef TSV_H
#define TSV_H

#include <string>

namespace tsv
{

std::string getColumn(const std::string& line, size_t pos);

void setColumn(std::string& line, size_t pos, const std::string& value);

void deleteColumn(std::string& line, size_t pos);

}  // namespace tsv

#endif // TSV_H
