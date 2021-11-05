#include <cmath>

#include "FringePolicy/AStarEucFringePolicy.h"
#include "Fringe/AStarFringe.h"

double EuclideanDistance(const Board& board) {
    double h = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = board[i][j] - '0';
            int x = cur / 3;
            int y = cur % 3;
            double dx = x - i;
            double dy = y - j;
            h += std::sqrt(dx*dx + dy*dy);
        }
    }

    return h;
}

Fringe::sptr AStarEucFringePolicy::makeFringe() const {
    return std::make_shared<AStarFringe>(EuclideanDistance);
}
