#ifndef __DFS_FRINGE_H__
#define __DFS_FRINGE_H__

#include <stack>

#include "Fringe.h"

class DFSFringe : public Fringe {
    std::stack<SearchNode::sptr> fringe;

protected:
    bool insertInFringe(const SearchNode::sptr&) override;
    SearchNode::sptr extractFromFringe() override;
};

#endif
