#ifndef __ASTAR_FRINGE_H__
#define __ASTAR_FRINGE_H__

#include <queue>
#include <unordered_map>

#include "Fringe.h"


class AStarFringe : public Fringe {
    struct Node {
        SearchNode::sptr node;
        double cost;
    };

    typedef double Heuristic(const Board&);

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> fringe;

    // Least costs so far for previously-inserted board configurations
    std::unordered_map<size_t, double> leastCosts;

    Heuristic* heuristic;

    friend bool operator>(const Node&, const Node&);

protected:
    bool insertInFringe(const SearchNode::sptr&) override;
    SearchNode::sptr extractFromFringe() override;

public:
    AStarFringe(Heuristic*);
};

bool operator>(const AStarFringe::Node&, const AStarFringe::Node&);

#endif
