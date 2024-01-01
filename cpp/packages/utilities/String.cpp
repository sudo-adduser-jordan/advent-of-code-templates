#include "pch.h"

#include "String.h"

namespace Utilities
{

	std::vector<int> string_to_int_vector(const std::string& str)
	{
		int number;
		std::vector<int> ints;
		std::stringstream iss(str);
		while (iss >> number)
		{
			ints.push_back(number);
		}
		return ints;
	}

	std::vector<unsigned long long int> string_to_long_long_vector(const std::string& str)
	{
		std::vector<unsigned long long int> ints;

		unsigned long long int number;
		std::stringstream iss(str);
		while (iss >> number)
		{
			ints.push_back(number);
		}

		return ints;
	}

	bool isFound(const std::string& match, const std::string& str)
	{
		if (str.find(match) < str.length())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::vector<std::string> string_split(std::string s, const char delimiter)
	{
		size_t start = 0;
		size_t end = s.find_first_of(delimiter);

		std::vector<std::string> output;

		while (end <= std::string::npos)
		{
			output.emplace_back(s.substr(start, end - start));

			if (end == std::string::npos)
			{
				break;
			}

			start = end + 1;
			end = s.find_first_of(delimiter, start);
		}

		return output;
	}

} // namespace Utilities
