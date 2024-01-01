#pragma once
#include "pch.h"

namespace Utilities
{
	std::vector<int> string_to_int_vector(const std::string& str);
	std::vector<unsigned long long int> string_to_long_long_vector(const std::string& str);
	bool isFound(const std::string& match, const std::string& str);
	std::vector<std::string> string_split(std::string s, const char delimiter);

} // namespace Utilities