#include "Fringe/AStarFringe.h"

AStarFringe::AStarFringe(Heuristic* h) : heuristic(h) {}

bool AStarFringe::insertInFringe(const SearchNode::sptr& node) {
    size_t hash = node->getBoard().hash();
    double cost = node->getPath().size() + heuristic(node->getBoard());

    if (leastCosts.contains(node->getBoard().hash())) {
        double leastNodeCost = leastCosts[hash];

        if (leastNodeCost <= cost) {
            // Already seen a cheaper node with the same board state, discard
            return false;
        }
    }

    fringe.push({ node, cost });
    leastCosts[hash] = cost;

    return true;
}

SearchNode::sptr AStarFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    Node top = fringe.top();
    fringe.pop();

    return top.node;
}

bool operator>(const AStarFringe::Node& lhs, const AStarFringe::Node& rhs) {
    return lhs.cost > rhs.cost;
}
