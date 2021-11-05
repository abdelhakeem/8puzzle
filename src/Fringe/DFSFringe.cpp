#include "Fringe/DFSFringe.h"

bool DFSFringe::insertInFringe(const SearchNode::sptr& node) {
    if (!contains(node)) {
        fringe.push(node);
        return true;
    }

    return false;
}

SearchNode::sptr DFSFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    SearchNode::sptr top = fringe.top();
    fringe.pop();

    return top;
}
