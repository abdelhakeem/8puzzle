#include "Fringe/BFSFringe.h"

bool BFSFringe::insertInFringe(const SearchNode::sptr& node) {
    if (!contains(node)) {
        fringe.push_back(node);
        return true;
    }

    return false;
}

SearchNode::sptr BFSFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    SearchNode::sptr front = fringe.front();
    fringe.pop_front();

    return front;
}
