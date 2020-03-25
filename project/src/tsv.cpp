#include <tsv.h>

namespace tsv
{

std::string getColumn(const std::string& line, size_t pos)
{
	size_t n = 0, prev_n = 0;
	for (size_t i = 0; i < pos; ++i)
	{
		prev_n = n;
		n = line.find('\t', n + 1);
	}
	return line.substr(prev_n + 1, n - prev_n);
}

void setColumn(std::string& line, size_t pos, const std::string& value)
{

}

void deleteColumn(std::string& line, size_t pos)
{

}

}  // namespace tsv
