#include "pch.h"

#include "../packages/utilities/Utilities.h"
#include "CodeGenerator.h"
#include "solutions/Solutions.h"

const std::unordered_set<std::string> validArgs = {
    "--sample", "--input", "--parta", "--partb",
    "--solution01", "--solution02", "--solution03", "--solution04", "--solution05",
    "--solution06", "--solution07", "--solution08", "--solution09", "--solution10",
    "--solution11", "--solution12", "--solution13", "--solution14", "--solution15",
    "--solution16", "--solution17", "--solution18", "--solution19", "--solution20",
    "--solution21", "--solution22", "--solution23", "--solution24", "--solution25"};

const std::vector<std::function<void(const std::filesystem::path &)>>
    SOLUTIONS_A = {
        Solutions01A::PrintSolution,
        Solutions02A::PrintSolution,
        Solutions03A::PrintSolution,
        Solutions04A::PrintSolution,
        Solutions05A::PrintSolution,
        Solutions06A::PrintSolution,
        Solutions07A::PrintSolution,
        Solutions08A::PrintSolution,
        Solutions09A::PrintSolution,
        Solutions10A::PrintSolution,
        Solutions11A::PrintSolution,
        Solutions12A::PrintSolution,
        Solutions13A::PrintSolution,
        Solutions14A::PrintSolution,
        Solutions15A::PrintSolution,
        Solutions16A::PrintSolution,
        Solutions17A::PrintSolution,
        Solutions18A::PrintSolution,
        Solutions19A::PrintSolution,
        Solutions20A::PrintSolution,
        Solutions21A::PrintSolution,
        Solutions22A::PrintSolution,
        Solutions23A::PrintSolution,
        Solutions24A::PrintSolution,
        Solutions25A::PrintSolution};

const std::vector<std::function<void(const std::filesystem::path)>>
    SOLUTIONS_B = {
        Solutions01B::PrintSolution,
        Solutions02B::PrintSolution,
        Solutions03B::PrintSolution,
        Solutions04B::PrintSolution,
        Solutions05B::PrintSolution,
        Solutions06B::PrintSolution,
        Solutions07B::PrintSolution,
        Solutions08B::PrintSolution,
        Solutions09B::PrintSolution,
        Solutions10B::PrintSolution,
        Solutions11B::PrintSolution,
        Solutions12B::PrintSolution,
        Solutions13B::PrintSolution,
        Solutions14B::PrintSolution,
        Solutions15B::PrintSolution,
        Solutions16B::PrintSolution,
        Solutions17B::PrintSolution,
        Solutions18B::PrintSolution,
        Solutions19B::PrintSolution,
        Solutions20B::PrintSolution,
        Solutions21B::PrintSolution,
        Solutions22B::PrintSolution,
        Solutions23B::PrintSolution,
        Solutions24B::PrintSolution,
        Solutions25B::PrintSolution};

const std::vector<std::filesystem::path>
    INPUT_PATHS = {
        "Input01.input",
        "Input02.input",
        "Input03.input",
        "Input04.input",
        "Input05.input",
        "Input06.input",
        "Input07.input",
        "Input08.input",
        "Input09.input",
        "Input10.input",
        "Input11.input",
        "Input12.input",
        "Input13.input",
        "Input14.input",
        "Input15.input",
        "Input16.input",
        "Input17.input",
        "Input18.input",
        "Input19.input",
        "Input20.input",
        "Input21.input",
        "Input22.input",
        "Input23.input",
        "Input24.input",
        "Input25.input",
};

const std::vector<std::filesystem::path>
    SAMPLE_PATHS = {
        "Sample01.input",
        "Sample02.input",
        "Sample03.input",
        "Sample04.input",
        "Sample05.input",
        "Sample06.input",
        "Sample07.input",
        "Sample08.input",
        "Sample09.input",
        "Sample10.input",
        "Sample11.input",
        "Sample12.input",
        "Sample13.input",
        "Sample14.input",
        "Sample15.input",
        "Sample16.input",
        "Sample17.input",
        "Sample18.input",
        "Sample19.input",
        "Sample20.input",
        "Sample21.input",
        "Sample22.input",
        "Sample23.input",
        "Sample24.input",
        "Sample25.input"};

struct Arguments
{
  bool sample = false;
  bool input = false;
  bool parta = false;
  bool partb = false;
  std::vector<int> solutionsInt;
  std::vector<std::string> solutionsString;
};

const std::string TITLE = "Advent of Code";
const std::string STAR = YELLOW_TEXT " * " RESET_COLOR;

void PrintTitle()
{
  int color = 0;
  std::cout << STAR;
  for (const auto &character : TITLE)
  {
    if (color == 0)
    {
      std::cout << GREEN_TEXT << character << RESET_COLOR;
      color = 1;
    }
    else
    {
      std::cout << RED_TEXT << character << RESET_COLOR;
      color = 0;
    }
  }
  std::cout << STAR << YELLOW_TEXT << "2023" << RESET_COLOR
            << std::endl
            << std::endl;
}

void PrintArguments(Arguments arguments)
{
  std::cout << STAR
            << "Command line arguments: "
            << std::endl
            << std::endl
            << GREEN_TEXT;
  if (arguments.input)
  {
    std::cout << "  --input";
  }
  if (arguments.sample)
  {
    std::cout << "  --sample";
  }
  if (arguments.parta)
  {
    std::cout << "  --parta";
  }
  if (arguments.partb)
  {
    std::cout << "  --partb";
  }
  for (const auto &solution : arguments.solutionsString)
  {
    std::cout << "  " << solution;
  }
  std::cout << RESET_COLOR
            << std::endl
            << std::endl;
}

void PrintArgumentError()
{
  std::cout << RED_TEXT
            << "\nNo Solutions specified for execution. Pass desired Solutions "
            << "as command-line arguments. Sample usage:\n"
            << RESET_COLOR;

  std::cout << "  AdventOfCode.exe "
            << GREEN_TEXT
            << "--Solution04\n"
            << RESET_COLOR;

  std::cout << "  AdventOfCode.exe "
            << GREEN_TEXT
            << "--render --Solution01 --Solution02\n"
            << RESET_COLOR;

  std::cout << "  AdventOfCode.exe "
            << GREEN_TEXT
            << "--partB --input --Solution02\n"
            << RESET_COLOR;

  std::cout << "  AdventOfCode.exe "
            << GREEN_TEXT
            << "--partA --sampleInput --Solution03\n"
            << RESET_COLOR
            << std::endl;
  std::exit(1);
}

Arguments ReadArgs(int argc, char *argv[])
{
  Arguments arguments;
  if (argc < 2)
  {
    PrintArgumentError();
  }
  if (argc >= 2)
  {
    for (int i = 1; i < argc; ++i)
    {
      std::string arg = argv[i];
      if (validArgs.contains(arg))
      {
        if (arg == "--sample")
        {
          arguments.sample = true;
        }
        else if (arg == "--input")
        {
          arguments.input = true;
        }
        else if (arg == "--partA")
        {
          arguments.parta = true;
        }
        else if (arg == "--partB")
        {
          arguments.partb = true;
        }
        else
        {
          arguments.solutionsString.push_back(arg);
          arguments.solutionsInt.push_back(std::stoi(arg.substr(arg.size() - 2)));
        }
      }
    }
  }

  if (!arguments.parta && !arguments.partb)
  {
    arguments.parta = true;
    arguments.partb = true;
  }

  if (!arguments.sample && !arguments.input)
  {
    arguments.sample = true;
    arguments.input = true;
  }

  std::ranges::sort(arguments.solutionsInt);
  std::ranges::sort(arguments.solutionsString);
  return arguments;
}

void ExecuteSolutions(Arguments arguments)
{

  for (const auto &day : arguments.solutionsInt)
  {
    for (auto index = 0; index <= 1; index++)
    {
      if (index == 0 and !arguments.parta)
      {
        continue;
      }
      if (index == 1 and !arguments.partb)
      {
        continue;
      }
      std::cout << STAR
                << "Running solution "
                << CYAN_TEXT
                << day
                << RESET_COLOR
                << ", part "
                << MAGENTA_TEXT;

      std::function<void(std::filesystem::path)> solver;
      if (index == 0)
      {
        solver = SOLUTIONS_A[day - 1];
        std::cout << "A";
      }
      if (index == 1)
      {
        solver = SOLUTIONS_B[day - 1];
        std::cout << "B";
      }
      std::cout << RESET_COLOR
                << std::endl
                << std::endl;

      std::vector<std::string> inputPaths;
      std::string directory = std::filesystem::current_path().string();
      if (arguments.sample)
      {
        inputPaths.push_back(directory + "/source/samples/" + SAMPLE_PATHS[day - 1].string());
      }
      if (arguments.input)
      {
        inputPaths.push_back(directory + "/source/inputs/" + INPUT_PATHS[day - 1].string());
      }
      for (const auto &path : inputPaths)
      {
        std::cout << "\t\tUsing input file: "
                  << CYAN_TEXT
                  << path
                  << RESET_COLOR
                  << std::endl
                  << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        solver(path);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;

        std::cout << RESET_COLOR;
        std::cout << "\t\tSolution executed in: "
                  << YELLOW_TEXT
                  << duration.count()
                  << " us"
                  << RESET_COLOR
                  << std::endl
                  << std::endl;
      }
    }
  }
}

int main(int argc, char *argv[])
{

  {
    // CodeGenerator::GenerateMarkDownFiles();
    // CodeGenerator::GenerateHeaders();
    // CodeGenerator::GenerateSolutions();
    // CodeGenerator::GenerateInputFiles();
  }

  {
    PrintTitle();                               // Print Title.
    Arguments arguments = ReadArgs(argc, argv); // Get Arguments.
    PrintArguments(arguments);                  // Print Arguments.
    ExecuteSolutions(arguments);                // Execute Solutions.}
  }
}