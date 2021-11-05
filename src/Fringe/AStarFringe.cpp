#include "Fringe/AStarFringe.h"

AStarFringe::AStarFringe(Heuristic* h) : heuristic(h) {}

bool AStarFringe::insertInFringe(const SearchNode::sptr& node) {
    double cost = node->getPath().size() + heuristic(node->getBoard());

    if (this->contains(node)) {
        double oldNodeCost = costMap[node->getBoard().hash()];

        if (cost < oldNodeCost) {
            costMap[node->getBoard().hash()] = cost;
        } else {
            // Old node is better, do nothing
            return false;
        }
    }

    fringe.push({ node, cost });
    costMap[node->getBoard().hash()] = cost;

    return true;
}

SearchNode::sptr AStarFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    Node top = fringe.top();
    fringe.pop();

    SearchNode::sptr node = top.first;
    costMap.erase(node->getBoard().hash());

    return node;
}

bool operator>(const AStarFringe::Node& lhs, const AStarFringe::Node& rhs) {
    return lhs.second > rhs.second;
}
