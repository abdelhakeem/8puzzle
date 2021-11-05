#ifndef __BFS_FRINGE_H__
#define __BFS_FRINGE_H__

#include <queue>

#include "Fringe.h"

class BFSFringe : public Fringe {
    std::queue<SearchNode::sptr> fringe;

protected:
    bool insertInFringe(const SearchNode::sptr&) override;
    SearchNode::sptr extractFromFringe() override;
};

#endif
