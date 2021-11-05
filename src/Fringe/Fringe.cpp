#include "Fringe/Fringe.h"

bool Fringe::contains(const SearchNode::sptr& node) const {
    return fringeSet.contains(node->getBoard().hash());
}

void Fringe::insert(const SearchNode::sptr& node) {
    if (insertInFringe(node)) {
        fringeSet.insert(node->getBoard().hash());
    }
}

void Fringe::insertAll(const std::vector<SearchNode::sptr>& nodes) {
    for (const auto& node : nodes) {
        insert(node);
    }
}

SearchNode::sptr Fringe::extract() {
    SearchNode::sptr node = extractFromFringe();

    if (node) {
        // Remove only one element
        fringeSet.erase(fringeSet.find(node->getBoard().hash()));
    }

    return node;
}
