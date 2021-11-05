#include "Fringe/DFSFringe.h"

bool DFSFringe::insertInFringe(const SearchNode::sptr& node) {
    if (!contains(node)) {
        fringe.push_back(node);
        return true;
    }

    return false;
}

SearchNode::sptr DFSFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    SearchNode::sptr back = fringe.back();
    fringe.pop_back();

    return back;
}
