#include "Solutions.h"
#include "../../packages/utilities/Utilities.h"

namespace Solutions10A
{
	void PrintSolution(const std::filesystem::path& inputFile, bool shouldRender)
	{
		auto input = Utilities::file_into_string_vector(inputFile);
		int result = 0;
		std::cout << "\t\t" << GREEN_TEXT << "\t\t" << result << std::endl;
	}
} // namespace Solutions10A
