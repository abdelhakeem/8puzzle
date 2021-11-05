#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <chrono>

#include "FringePolicy/FringePolicy.h"

struct Result {
    bool solved;
    Board initialBoard;
    std::vector<Direction> path;
    size_t nodesExpanded;
    size_t searchDepth;
    std::chrono::nanoseconds nsRunningTime;
};

class Solver {
    virtual void abstract() = 0;

public:
    static Result solve(const Board&, FringePolicy::sptr,
                        size_t maxNodes, size_t maxDepth);
};

#endif
