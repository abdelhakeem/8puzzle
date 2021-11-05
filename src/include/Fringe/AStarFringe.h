#ifndef __ASTAR_FRINGE_H__
#define __ASTAR_FRINGE_H__

#include <queue>
#include <unordered_map>

#include "Fringe.h"


class AStarFringe : public Fringe {
    typedef std::pair<SearchNode::sptr, size_t> Node;
    typedef double Heuristic(const Board&);

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> fringe;
    std::unordered_map<size_t, double> costMap;
    Heuristic* heuristic;

    friend bool operator>(const Node&, const Node&);

public:
    AStarFringe(Heuristic*);

    bool insertInFringe(const SearchNode::sptr&) override;
    SearchNode::sptr extractFromFringe() override;
};

bool operator>(const AStarFringe::Node&, const AStarFringe::Node&);

#endif
