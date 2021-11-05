#ifndef __SEARCH_NODE_H__
#define __SEARCH_NODE_H__

#include <memory>
#include <vector>

#include "Board.h"

class SearchNode {
    Board board;
    std::vector<Direction> path;

public:
    typedef std::shared_ptr<SearchNode> sptr;

    SearchNode(const Board&);

    std::vector<SearchNode::sptr> expand() const;
    const Board& getBoard() const;
    const std::vector<Direction>& getPath() const;
};

#endif
