#include "pch.h"
#include "CodeGenerator.h"
#include "../packages/utilities/Utilities.h"

const int TOTAL_FILES = 25;
const std::string INPUT_PATH = "./source/inputs/";
const std::string SAMPLES_PATH = "./source/samples/";
const std::string PROBLEMS_PATH = "./source/problems/";
const std::string SOLUTIONS_PATH = "./source/solutions/";

namespace CodeGenerator
{

	void GenerateMarkDownFiles()
	{
		std::filesystem::create_directories(PROBLEMS_PATH);
		auto lines = std::vector<std::string>{ "" };
		for (auto i = 1; i <= TOTAL_FILES; ++i)
		{
			for (auto j = 0; j < 2; ++j)
			{
				char part = (j == 0 ? 'A' : 'B');
				auto builder = std::stringstream{};
				builder << PROBLEMS_PATH << "Problem" << std::setfill('0') << std::setw(2) << i << part << ".md";
				Utilities::string_vector_vector_to_file(builder.str(), lines);
			}
		}
	}

	void GenerateHeaders()
	{
		auto lines = std::vector<std::string>{ "#pragma once" };

		for (auto i = 1; i <= TOTAL_FILES; ++i)
		{
			for (auto j = 0; j < 2; ++j)
			{
				const auto suffix = j == 0 ? 'A' : 'B';

				lines.emplace_back("");

				auto builder = std::stringstream{};
				builder << "namespace Solutions" << std::setfill('0') << std::setw(2) << i << suffix;
				lines.emplace_back(builder.str());
				lines.emplace_back("{");
				lines.emplace_back("\tvoid PrintSolution(const std::filesystem::path& inputFile, bool shouldRender);");
				lines.emplace_back("}");
			}
		}

		Utilities::string_vector_vector_to_file("source/solutions/Solutions.h", lines);
	}

	void GenerateSolutions()
	{
		std::filesystem::create_directories(SOLUTIONS_PATH);

		// line # 5, 13
		std::string line5 = "namespace Solutions";
		std::string line13 = "} // namespace Solutions";

		std::ifstream input_file("./build/debug/SolutionTemplate.txt");
		std::vector<std::string> lines;
		std::string input;

		while (std::getline(input_file, input))
		{
			lines.push_back(input);
			std::cout << input << std::endl;
		}
		input_file.close();

		for (auto i = 1; i <= TOTAL_FILES; i++)
		{
			for (auto j = 0; j < 2; ++j)
			{
				char part = (j == 0 ? 'A' : 'B');
				std::string day = (i < 10 ? '0' + std::to_string(i) : std::to_string(i));
				std::string output_file =  SOLUTIONS_PATH + "Solution" + day + part + ".cpp";

				lines[4] = line5 + day + part;
				lines[12] = line13 + day + part;

				std::cout << lines[12] << std::endl;
				Utilities::string_vector_vector_to_file(output_file, lines);
			}
		}
	}

	void GenerateInputFiles()
	{
		std::filesystem::create_directories(INPUT_PATH);
		std::filesystem::create_directories(SAMPLES_PATH);
		auto lines = std::vector<std::string>{ "" };
		for (auto i = 1; i <= TOTAL_FILES; ++i)
		{
			{
				auto builder = std::stringstream{};
				builder << INPUT_PATH << "Problem" << std::setfill('0') << std::setw(2) << i << ".input";
				Utilities::string_vector_vector_to_file(builder.str(), lines);
			}

			{
				auto builder = std::stringstream{};
				builder << SAMPLES_PATH << "Sample" << std::setfill('0') << std::setw(2) << i << ".input";
				Utilities::string_vector_vector_to_file(builder.str(), lines);
			}
		}
	}
} // namespace CodeGenerator