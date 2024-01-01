#pragma once
#include "pch.h"

namespace Utilities
{
	std::vector<std::vector<int>> file_into_int_grid(const std::filesystem::path& path);
	std::vector<std::string> file_into_string_vector(const std::filesystem::path& path);
	bool string_vector_vector_to_file(const std::filesystem::path& path, const std::vector<std::string>& lines);
} // namespace Utilities