#include <iostream>
#include <libgen.h>
#include <unistd.h>
#include <unordered_map>

#include "Output.h"
#include "Solver.h"

#include "FringePolicy/BFSFringePolicy.h"
#include "FringePolicy/DFSFringePolicy.h"
#include "FringePolicy/AStarManFringePolicy.h"
#include "FringePolicy/AStarEucFringePolicy.h"
#include "FringePolicy/AStarMisplacedFringePolicy.h"

int main(int argc, char* argv[]) {
    std::string usage = std::string("USAGE: ") +
        basename(argv[0]) +
        " [-a <algorithm>] [-n <nodes>] [-d <depth>] <board>\n\n"
        "  <algorithm>\n\n"
        "    bfs   Breadth-First Search\n"
        "    dfs   Depth-First Search\n"
        "    aman  A-Star Search using Manhattan distance heuristic\n"
        "    aeuc  A-Star Search using Euclidean distance heuristic\n"
        "    amis  A-Star Search using misplaced tiles count heuristic\n\n"
        "  <nodes>      Maximum number of nodes to expand\n"
        "  <depth>      Maximum search depth\n"
        "  <board>      Initial board configuration (e.g.: 102345678)\n";

    if (argc == 1) {
        std::cout << usage;
        return 0;
    }

    std::unordered_map<std::string, std::string> policiesStr = {
        { "bfs", "BFS" },
        { "dfs", "DFS" },
        { "aman", "A-Star using Manhattan distance heuristic" },
        { "aeuc", "A-Star using Euclidean distance heuristic" },
        { "amis", "A-Star Search using misplaced tiles count heuristic" }
    };

    std::unordered_map<std::string, FringePolicy::sptr> policies =
    {
        { "bfs",  std::make_shared<BFSFringePolicy>() },
        { "dfs",  std::make_shared<DFSFringePolicy>() },
        { "aman",  std::make_shared<AStarManFringePolicy>() },
        { "aeuc",  std::make_shared<AStarEucFringePolicy>() },
        { "amis",  std::make_shared<AStarMisplacedFringePolicy>() }
    };

    try {
        std::string policyStr;
        FringePolicy::sptr policy = nullptr;  // default: all algorithms

        size_t maxNodes = 0;
        size_t maxDepth = 0;

        // Parse arguments

        opterr = 0;
        int c;
        std::string tmpStr;
        size_t numChars;

        while ((c = getopt(argc, argv, ":a:n:d:")) != -1) {
            switch (c) {
                case 'a':
                    policyStr = optarg;

                    if (!policies.contains(policyStr)) {
                        std::cout << usage;
                        return 1;
                    }

                    policy = policies[policyStr];
                    break;
                case 'n':
                    tmpStr = optarg;
                    maxNodes = std::stoll(tmpStr, &numChars);
                    if (numChars != tmpStr.size()) {
                        std::cout << usage;
                        return 1;
                    }
                    break;
                case 'd':
                    tmpStr = optarg;
                    maxDepth = std::stoll(tmpStr, &numChars);
                    if (numChars != tmpStr.size()) {
                        std::cout << usage;
                        return 1;
                    }
                    break;
                case '?':
                    break;
                default:
                    std::cout << usage;
                    return 1;
            }
        }

        if (optind >= argc) {
            std::cout << usage;
            return 1;
        }

        Board board(argv[optind]);

        // Solve and print results

        if (policy) {
            std::cout << "Solution with " << policiesStr[policyStr] << ":\n"
                      << std::endl;
            std::cout << Solver::solve(board, policy, maxNodes, maxDepth);
        } else {
            for (const auto& p : policies) {
                std::cout << "Solution with " << policiesStr[p.first] << ":\n"
                          << std::endl;
                Result res = Solver::solve(board, p.second,
                                           maxNodes, maxDepth);
                std::cout << summarizeResult(res) << std::endl;
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "ERROR: " << ex.what() << std::endl;
    }

    return 0;
}
