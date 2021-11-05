#include <functional>

#include "SearchNode.h"

SearchNode::SearchNode(const Board& board) :
    board(board), path(std::vector<Direction>()) {}

std::vector<SearchNode::sptr> SearchNode::expand() const {
    static Direction directions[] = {
        Direction::Up,
        Direction::Down,
        Direction::Right,
        Direction::Left
    };

    std::vector<SearchNode::sptr> children;

    for (Direction direction : directions) {
        SearchNode::sptr child = std::make_shared<SearchNode>(*this);

        if (child->board.moveTile(direction)) {
            child->path.push_back(direction);
            children.push_back(child);
        } else {
            child.reset();
        }
    }

    return children;
}

const Board& SearchNode::getBoard() const {
    return board;
}

const std::vector<Direction>& SearchNode::getPath() const {
    return path;
}
