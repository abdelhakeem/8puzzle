#include <unordered_set>

#include "Solver.h"

Result Solver::solve(const Board& board, FringePolicy::sptr policy,
                     size_t maxNodes, size_t maxDepth) {
    Result res = {
        .solved = false,
        .initialBoard = board,
        .path = std::vector<Direction>(),
        .nodesExpanded = 0,
        .searchDepth = 0,
        .nsRunningTime = std::chrono::nanoseconds(0)
    };

    Fringe::sptr fringe = policy->makeFringe();
    std::unordered_set<size_t> expanded;
    SearchNode::sptr node;

    fringe->insert(std::make_shared<SearchNode>(board));

    auto t1 = std::chrono::steady_clock::now();

    while ((node = fringe->extract())) {
        if (!expanded.contains(node->getBoard().hash())) {
            size_t depth = node->getPath().size();
            res.searchDepth = std::max(res.searchDepth, depth);
            res.nodesExpanded++;

            if (node->getBoard().solved()) {
                auto t2 = std::chrono::steady_clock::now();
                res.solved = true;
                res.nsRunningTime = t2 - t1;
                res.path = node->getPath();

                return res;
            }

            bool tooDeep = maxDepth && res.searchDepth > maxDepth;
            bool tooManyNodes = maxNodes && res.nodesExpanded >= maxNodes;

            if (tooDeep || tooManyNodes) {
                auto t2 = std::chrono::steady_clock::now();
                res.nsRunningTime = t2 - t1;

                return res;
            }

            fringe->insertAll(node->expand());
            expanded.insert(node->getBoard().hash());
        }
    }

    // Exhausted search space and found no solution
    auto t2 = std::chrono::steady_clock::now();
    res.nsRunningTime = t2 - t1;

    return res;
}
