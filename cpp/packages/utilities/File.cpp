#include "pch.h"

#include "File.h"
#include "String.h"

namespace Utilities
{
	std::vector<std::string> file_into_string_vector(const std::filesystem::path& path)
	{
		std::string line;
		std::vector<std::string> lines;
		std::ifstream file(path);
		while (getline(file, line))
		{
			lines.push_back(line);
		}
		return lines;
	}

	std::vector<std::vector<int>> file_into_int_grid(const std::filesystem::path& path)
	{
		int number = 0;
		std::string line;
		std::vector<std::vector<int>> grid;
		std::ifstream file(path);
		while (std::getline(file, line))
		{
			grid.push_back(string_to_int_vector(line));
		}
		return grid;
	}

	bool string_vector_vector_to_file(const std::filesystem::path& path, const std::vector<std::string>& lines)
	{
		auto fileStream = std::ofstream{ path };
		if (!fileStream.good())
		{
			std::cout << "Error writing to file." << std::endl;
			return false;
		}

		for (auto i = 1; i < lines.size(); i++)
		{
			fileStream << lines[i] << std::endl;
		}

		return fileStream.good();
	}

} // namespace Utilities
