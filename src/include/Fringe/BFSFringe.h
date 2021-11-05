#ifndef __BFS_FRINGE_H__
#define __BFS_FRINGE_H__

#include <deque>

#include "Fringe.h"

class BFSFringe : public Fringe {
    std::deque<SearchNode::sptr> fringe;

public:
    bool insertInFringe(const SearchNode::sptr&) override;
    SearchNode::sptr extractFromFringe() override;
};

#endif
