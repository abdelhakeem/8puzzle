#include <algorithm>
#include <cassert>

#include "Fringe/AStarFringe.h"

int main() {
    std::unordered_map<Direction, Direction> antiDir {
        { Direction::Up, Direction::Down },
        { Direction::Down, Direction::Up },
        { Direction::Left, Direction::Right },
        { Direction::Right, Direction::Left }
    };

    auto moveTile = [](const SearchNode::sptr& n, Direction d) {
        auto c = n->expand();

        auto it = find_if(c.begin(), c.end(), [d](const auto& n) {
            return n->getPath().back() == d;
        });

        return it == c.end() ? nullptr : *it;
    };

    auto makeNode = [antiDir, moveTile](const std::string& cfg, int cost) {
        auto n1 = std::make_shared<SearchNode>(Board(cfg));

        for (const auto& dirPair : antiDir) {
            auto n2 = moveTile(n1, dirPair.first);

            if (n2) {
                if (cost & 1) {
                    *n1 = SearchNode(n2->getBoard());
                    n1 = moveTile(n1, dirPair.second);
                    cost--;
                }

                while (cost) {
                    n1 = moveTile(n1, dirPair.first);
                    n1 = moveTile(n1, dirPair.second);
                    cost -= 2;
                }

                return n1;
            }
        }

        return n1;
    };

    std::vector<SearchNode::sptr> nodes(7);

    for (int i = 0; i < 7; i++) {
        nodes[i] = makeNode("102345678", i);
    }

    for (size_t i = 0; i < 7; i++) {
        assert(nodes[i]->getPath().size() == i);
        assert(nodes[i]->getBoard().hash() == 102345678);
    }

    AStarFringe fringe([](const Board&) -> double { return 0; });

    // Descending order, should all be inserted
    std::reverse(nodes.begin(), nodes.end());
    fringe.insertAll(nodes);
    std::reverse(nodes.begin(), nodes.end());

    for (size_t i = 0; i < 7; i++) {
        assert(fringe.extract() == nodes[i]);
    }

    assert(fringe.extract() == nullptr);

    // Now nothing should be inserted since we have already
    // seen a node with the same board configuration and with cost = 0
    fringe.insertAll(nodes);
    assert(fringe.extract() == nullptr);

    std::reverse(nodes.begin(), nodes.end());
    fringe.insertAll(nodes);
    assert(fringe.extract() == nullptr);

    return 0;
}
