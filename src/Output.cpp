#include <sstream>
#include <unordered_map>

#include "Output.h"

static std::unordered_map<Direction, std::string> actionStr = {
    { Direction::Up,    "Up" },
    { Direction::Down,  "Down" },
    { Direction::Right, "Right" },
    { Direction::Left,  "Left" }
};

std::string summarizeResult(const Result& res) {
    std::ostringstream oss;
    oss << "Search depth: " << res.searchDepth << std::endl
        << "Nodes expanded: " << res.nodesExpanded << std::endl
        << "Running time: " << res.nsRunningTime.count() << " ns" << std::endl
        << "Path cost: " << res.path.size() << std::endl;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << (board[i][j] == '0' ? ' ' : board[i][j])
               << (j < 2 ? ' ' : '\n');
        }
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Result& res) {
    Board board = res.initialBoard;

    os << board << std::endl;

    for (Direction action : res.path) {
        board.moveTile(action);
        os << "  |\n"
           << "  | " << actionStr[action] << "\n"
           << "  |\n"
           << "  V\n\n"
           << board << std::endl;
    }

    os << summarizeResult(res) << std::endl;

    return os;
}
