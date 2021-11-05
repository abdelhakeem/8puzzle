#include <cmath>

#include "FringePolicy/AStarManFringePolicy.h"
#include "Fringe/AStarFringe.h"

double ManhattanDistance(const Board& board) {
    double h = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = board[i][j] - '0';
            int x = cur / 3;
            int y = cur % 3;
            h += std::abs(x - i) + std::abs(y - j);
        }
    }

    return h;
}

Fringe::sptr AStarManFringePolicy::makeFringe() const {
    return std::make_shared<AStarFringe>(ManhattanDistance);
}
