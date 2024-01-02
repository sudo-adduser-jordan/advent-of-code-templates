#include "pch.h"

#include "../packages/utilities/Utilities.h"
#include "CodeGenerator.h"

const std::unordered_set<std::string> validArgs = {
    "--sample", "--input", "--render",   "--parta",    "--partb",
    "--solution01",    "--solution02",  "--solution03", "--solution04", "--solution05",
    "--solution06",    "--solution07",  "--solution08", "--solution09", "--solution10",
    "--solution11",    "--solution12",  "--solution13", "--solution14", "--solution15",
    "--solution16",    "--solution17",  "--solution18", "--solution19", "--solution20",
    "--solution21",    "--solution22",  "--solution23", "--solution24", "--solution25"};

// const std::vector<std::function<void(const std::filesystem::path &, bool)>>
//     partASolvers = {Solution01A::PrintSolution, Solution02A::PrintSolution,
//                     Solution03A::PrintSolution, Solution04A::PrintSolution,
//                     Solution05A::PrintSolution, Solution06A::PrintSolution,
//                     Solution07A::PrintSolution, Solution08A::PrintSolution,
//                     Solution09A::PrintSolution, Solution10A::PrintSolution,
//                     Solution11A::PrintSolution, Solution12A::PrintSolution,
//                     Solution13A::PrintSolution, Solution14A::PrintSolution,
//                     Solution15A::PrintSolution, Solution16A::PrintSolution,
//                     Solution17A::PrintSolution, Solution18A::PrintSolution,
//                     Solution19A::PrintSolution, Solution20A::PrintSolution,
//                     Solution21A::PrintSolution, Solution22A::PrintSolution,
//                     Solution23A::PrintSolution, Solution24A::PrintSolution,
//                     Solution25A::PrintSolution};

// const std::vector<std::function<void(const std::filesystem::path &, bool)>>
//     partBSolvers = {Solution01B::PrintSolution, Solution02B::PrintSolution,
//                     Solution03B::PrintSolution, Solution04B::PrintSolution,
//                     Solution05B::PrintSolution, Solution06B::PrintSolution,
//                     Solution07B::PrintSolution, Solution08B::PrintSolution,
//                     Solution09B::PrintSolution, Solution10B::PrintSolution,
//                     Solution11B::PrintSolution, Solution12B::PrintSolution,
//                     Solution13B::PrintSolution, Solution14B::PrintSolution,
//                     Solution15B::PrintSolution, Solution16B::PrintSolution,
//                     Solution17B::PrintSolution, Solution18B::PrintSolution,
//                     Solution19B::PrintSolution, Solution20B::PrintSolution,
//                     Solution21B::PrintSolution, Solution22B::PrintSolution,
//                     Solution23B::PrintSolution, Solution24B::PrintSolution,
//                     Solution25B::PrintSolution};

// const std::vector<std::vector<std::filesystem::path>> SolutionInputPaths = {
//     {"Solution01.input"}, {"Solution02.input"}, {"Solution03.input"},
//     {"Solution04.input"}, {"Solution05.input"}, {"Solution06.input"},
//     {"Solution07.input"}, {"Solution08.input"}, {"Solution09.input"},
//     {"Solution10.input"}, {"Solution11.input"}, {"Solution12.input"},
//     {"Solution13.input"}, {"Solution14.input"}, {"Solution15.input"},
//     {"Solution16.input"}, {"Solution17.input"}, {"Solution18.input"},
//     {"Solution19.input"}, {"Solution20.input"}, {"Solution21.input"},
//     {"Solution22.input"}, {"Solution23.input"}, {"Solution24.input"},
//     {"Solution25.input"},
// };

// const std::vector<std::vector<std::vector<std::filesystem::path>>>
//     SolutionSamplePaths = {{
//                              {"Solution01SampleA.input"},
//                              {"Solution01SampleB.input"},
//                          },
//                          {
//                              {"Solution02SampleA.input"},
//                              {"Solution02SampleA.input"},
//                          },
//                          {
//                              {"Solution03SampleA.input"},
//                              {"Solution03SampleA.input"},
//                          },
//                          {
//                              {"Solution04SampleA.input"},
//                              {"Solution04SampleA.input"},
//                          },
//                          {
//                              {"Solution05SampleA.input"},
//                              {"Solution05SampleA.input"},
//                          },
//                          {
//                              {"Solution06SampleA.input"},
//                              {"Solution06SampleA.input"},
//                          },
//                          {
//                              {"Solution07SampleA.input"},
//                              {"Solution07SampleA.input"},
//                          },
//                          {
//                              {"Solution08SampleA.input"},
//                              {"Solution08SampleA.input"},
//                          },
//                          {
//                              {"Solution09SampleA.input"},
//                              {"Solution09SampleA.input"},
//                          },
//                          {
//                              {"Solution10SampleA.input"},
//                              {"Solution10SampleA.input"},
//                          },
//                          {
//                              {"Solution11SampleA.input"},
//                              {"Solution11SampleA.input"},
//                          },
//                          {
//                              {"Solution12SampleA.input"},
//                              {"Solution12SampleA.input"},
//                          },
//                          {
//                              {"Solution13SampleA.input"},
//                              {"Solution13SampleA.input"},
//                          },
//                          {
//                              {"Solution14SampleA.input"},
//                              {"Solution14SampleA.input"},
//                          },
//                          {
//                              {"Solution15SampleA.input"},
//                              {"Solution15SampleA.input"},
//                          },
//                          {
//                              {"Solution16SampleA.input"},
//                              {"Solution16SampleA.input"},
//                          },
//                          {
//                              {"Solution17SampleA.input"},
//                              {"Solution17SampleA.input"},
//                          },
//                          {
//                              {"Solution18SampleA.input"},
//                              {"Solution18SampleA.input"},
//                          },
//                          {
//                              {"Solution19SampleA.input"},
//                              {"Solution19SampleA.input"},
//                          },
//                          {
//                              {"Solution20SampleA.input"},
//                              {"Solution20SampleA.input"},
//                          },
//                          {
//                              {"Solution21SampleA.input"},
//                              {"Solution21SampleA.input"},
//                          },
//                          {
//                              {"Solution22SampleA.input"},
//                              {"Solution22SampleA.input"},
//                          },
//                          {
//                              {"Solution23SampleA.input"},
//                              {"Solution23SampleA.input"},
//                          },
//                          {
//                              {"Solution24SampleA.input"},
//                              {"Solution24SampleA.input"},
//                          },
//                          {
//                              {"Solution25SampleA.input"},
//                              {"Solution25SampleA.input"},
//                          }};

// struct Args {
//   bool useSampleInput = false;
//   bool useFullInput = false;
//   bool shouldRender = false;
//   bool runPartA = false;
//   bool runPartB = false;
//   std::vector<int> SolutionsToRun;
// };

// Args ReadArgs(int argc, char *argv[]) {
//   {
//     std::cout << YELLOW_TEXT;
//     std::cout << " * ";
//     std::cout << RESET_COLOR;
//   }

//   std::string header = "Advent of Code";
//   for (int i = 0; i < header.size(); ++i) {
//     if (i % 2 == 0) {
//       std::cout << GREEN_TEXT;
//     }

//     if (i % 2 == 1) {
//       std::cout << RED_TEXT;
//     }

//     std::cout << header[i];
//   }

//   {
//     std::cout << YELLOW_TEXT;
//     std::cout << " * ";
//     std::cout << " 2023\n\n";
//   }

//   Args result;
//   if (argc > 1) {
//     {
//       std::cout << YELLOW_TEXT;
//       std::cout << " * ";
//       std::cout << RESET_COLOR;
//       std::cout << "Command line arguments:\n";
//     }

//     for (int i = 1; i < argc; ++i) {
//       std::string arg = argv[i];
//       if (validArgs.contains(arg)) {
//         std::cout << GREEN_TEXT << std::endl;

//         if (arg == "--sampleInput") {
//           result.useSampleInput = true;
//         } else if (arg == "--fullInput") {
//           result.useFullInput = true;
//         } else if (arg == "--render") {
//           result.shouldRender = true;
//         } else if (arg == "--partA") {
//           result.runPartA = true;
//         } else if (arg == "--partB") {
//           result.runPartB = true;
//         } else {
//           result.SolutionsToRun.push_back(std::stoi(arg.substr(arg.size() - 2)));
//         }
//       } else {
//         std::cout << RED_TEXT;
//       }

//       std::cout << "    " << argv[i] << "\n\n";
//     }
//   }

//   if (!result.runPartA && !result.runPartB) {
//     result.runPartA = true;
//     result.runPartB = true;
//   }

//   if (!result.useSampleInput && !result.useFullInput) {
//     result.useSampleInput = true;
//     result.useFullInput = true;
//   }


//   // std::ranges::sort(result.SolutionsToRun);
//   return result;
// }

int main(int argc, char *argv[]) {

CodeGenerator::GenerateMarkDownFiles();
CodeGenerator::GenerateHeaders();
CodeGenerator::GenerateSolutions();
CodeGenerator::GenerateInputFiles();

  // Args args = ReadArgs(argc, argv);
  // if (args.SolutionsToRun.empty()) {
  //   std::cout << RED_TEXT;
  //   std::cout << "\nNo Solutions specified for execution. Pass desired Solutions "
  //                "as command-line arguments. Sample usage:\n";
  //   std::cout << RESET_COLOR;

  //   std::cout << "  AdventOfCode.exe ";
  //   std::cout << GREEN_TEXT;
  //   std::cout << "--Solution04\n";
  //   std::cout << RESET_COLOR;

  //   std::cout << "  AdventOfCode.exe ";
  //   std::cout << GREEN_TEXT;
  //   std::cout << "--render --Solution01 --Solution02\n";
  //   std::cout << RESET_COLOR;

  //   std::cout << "  AdventOfCode.exe ";
  //   std::cout << GREEN_TEXT;
  //   std::cout << "--partB --fullInput --Solution02\n";
  //   std::cout << RESET_COLOR;

  //   std::cout << "  AdventOfCode.exe ";
  //   std::cout << GREEN_TEXT;
  //   std::cout << "--partA --sampleInput --Solution03\n";
  //   std::cout << RESET_COLOR;
  // }

  // for (int SolutionId : args.SolutionsToRun) {
  //   for (auto i = 0; i < 2; ++i) {
  //     if (i == 0 && !args.runPartA) {
  //       continue;
  //     }

  //     if (i == 1 && !args.runPartB) {
  //       continue;
  //     }

  //     {
  //       std::cout << RESET_COLOR;
  //       std::cout << YELLOW_TEXT;
  //       std::cout << " * ";
  //       std::cout << RESET_COLOR;
  //       std::cout << "Running Solution ";
  //       std::cout << CYAN_TEXT;
  //       std::cout << SolutionId;
  //       std::cout << RESET_COLOR;
  //       std::cout << ", part ";

  //       std::cout << MAGENTA_TEXT;
  //       std::cout << (i == 0 ? 'A' : 'B');
  //       std::cout << RESET_COLOR;
  //       std::cout << ":\n\n";
  //     }

  //     std::vector<std::filesystem::path> inputPaths;
  //     if (args.useSampleInput) {
  //       inputPaths.append_range(SolutionSamplePaths[SolutionId - 1][i]);
  //     }
  //     if (args.useFullInput) {
  //       inputPaths.append_range(SolutionInputPaths[SolutionId - 1]);
  //     }

  //     const auto solver =
  //         i == 0 ? partASolvers[SolutionId - 1] : partBSolvers[SolutionId - 1];
  //     for (const auto &inputPath : inputPaths) {
  //       {
  //         std::cout << RESET_COLOR;
  //         std::cout << "\tUsing input file ";
  //         std::cout << CYAN_TEXT;
  //         std::cout << inputPath;
  //         std::cout << RESET_COLOR;
  //         std::cout << ":\n\n";
  //       }

  //       // Fully qualify the path to the input files, which have been copied
  //       // next to the executable.
  //       static const std::filesystem::path executablePath = argv[0];
  //       std::filesystem::path fullInputPath =
  //           executablePath.parent_path() / inputPath;

  //       auto start = std::chrono::high_resolution_clock::now();
  //       solver(fullInputPath, args.shouldRender);
  //       auto stop = std::chrono::high_resolution_clock::now();
  //       auto durationMs =
  //           std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

  //       {
  //         std::cout << RESET_COLOR << std::endl;
  //         std::cout << "\n\tSolver executed in ";
  //         std::cout << YELLOW_TEXT;
  //         std::cout << durationMs.count() << " ms";
  //         std::cout << RESET_COLOR << std::endl;
  //         std::cout << "\n\n";
  //       }
  //     }
  //   }
  // }



}