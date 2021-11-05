#include "FringePolicy/AStarMisplacedFringePolicy.h"
#include "Fringe/AStarFringe.h"

double MisplacedTiles(const Board& board) {
    double h = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = board[i][j] - '0';
            int x = cur / 3;
            int y = cur % 3;

            if (x != i || y != j) {
                h += 1;
            }
        }
    }

    return h;
}

Fringe::sptr AStarMisplacedFringePolicy::makeFringe() const {
    return std::make_shared<AStarFringe>(MisplacedTiles);
}
