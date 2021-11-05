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

    struct Cost {
        // Number of similar nodes
        int count;

        // Least cost value so far for the associated configuration
        double value;
    };

    typedef double Heuristic(const Board&);

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> fringe;

    // <Board::hash(), Cost>
    //
    // When inserting a node with a repeated board configuration, only insert
    // it if its cost is less than the least cost known so far for the given
    // configuration (even if the node associated with that least cost has
    // already been extracted from the fringe, as long as the fringe still
    // contains at least one similar node regardless of its cost, i.e.:
    //
    //     Cost.count > 0
    std::unordered_map<size_t, Cost> costMap;

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
