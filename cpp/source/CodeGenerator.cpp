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
				builder << "namespace Problem" << std::setfill('0') << std::setw(2) << i << suffix;
				lines.emplace_back(builder.str());
				lines.emplace_back("{");
				lines.emplace_back("\tvoid PrintSolution(const std::filesystem::path& inputFile, bool shouldRender);");
				lines.emplace_back("}");
			}
		}

		Utilities::string_vector_vector_to_file("ProblemSolvers.h", lines);
	}

	void GenerateSolutions()
	{
		// line # 9, 15, 17
		// namespace Problem
		//		std::cout << "Problem not yet solved!";
		// } // namespace Problem

		std::string line9 = "namespace Problem";
		std::string line15a = R"(		std::cout << "\t\tProblem)";
		std::string line15b = R"( not yet solved !";)";
		std::string line17 = "} // namespace Problem";

		std::ifstream input_file("ProblemTemplate.txt");
		std::vector<std::string> lines;
		std::string input;

		while (std::getline(input_file, input))
		{
			lines.push_back(input);
		}
		input_file.close();

		for (auto i = 6; i <= TOTAL_FILES; i++)
		{
			for (auto j = 0; j < 2; ++j)
			{
				char part = (j == 0 ? 'A' : 'B');
				std::string day = (i < 10 ? '0' + std::to_string(i) : std::to_string(i));
				std::string output_file = "Problem" + day + part + ".cpp";

				std::string line9New = line9;
				std::string line22New = line15a;
				std::string line17New = line17;

				line9New += day + part;
				line22New += day + part + line15b;
				line17New += day + part;

				lines[8] = line9New;
				lines[14] = line22New;
				lines[16] = line17New;

				Utilities::string_vector_vector_to_file(output_file, lines);
				// std::cout << "File created.\n";
			}
		}
	}

	void GenerateInputFiles()
	{
		auto lines = std::vector<std::string>{ "" };
		for (auto i = 1; i <= TOTAL_FILES; ++i)
		{
			{
				auto builder = std::stringstream{};
				builder << "Problem" << std::setfill('0') << std::setw(2) << i << ".input";
				Utilities::string_vector_vector_to_file(builder.str(), lines);
			}

			{
				auto builder = std::stringstream{};
				builder << "Problem" << std::setfill('0') << std::setw(2) << i << "SampleA.input";
				Utilities::string_vector_vector_to_file(builder.str(), lines);
			}
		}
	}


} // namespace CodeGenerator