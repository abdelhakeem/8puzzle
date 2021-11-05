#include "Fringe/AStarFringe.h"

AStarFringe::AStarFringe(Heuristic* h) : heuristic(h) {}

bool AStarFringe::insertInFringe(const SearchNode::sptr& node) {
    size_t hash = node->getBoard().hash();
    double cost = node->getPath().size() + heuristic(node->getBoard());

    if (this->contains(node)) {
        Cost oldCost = costMap[hash];

        if (cost < oldCost.value) {
            Cost newCost = {
                .count = oldCost.count + 1,
                .value = cost
            };

            fringe.push({ node, cost });
            costMap[hash] = newCost;

            return true;
        } else {
            // Old node similar or better, do nothing
            return false;
        }
    }

    fringe.push({ node, cost });
    costMap[hash] = {
        .count = 1,
        .value = cost
    };

    return true;
}

SearchNode::sptr AStarFringe::extractFromFringe() {
    if (fringe.empty()) {
        return nullptr;
    }

    Node top = fringe.top();
    fringe.pop();

    SearchNode::sptr node = top.node;

    size_t hash = node->getBoard().hash();
    costMap[hash].count--;

    if (costMap[hash].count == 0) {
        costMap.erase(hash);
    }

    return node;
}

bool operator>(const AStarFringe::Node& lhs, const AStarFringe::Node& rhs) {
    return lhs.cost > rhs.cost;
}
