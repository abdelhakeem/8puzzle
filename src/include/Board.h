#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <utility>

enum class Direction { Up, Down, Right, Left };

class Board {
    char board[3][3];
    std::pair<int, int> emptyTile;

public:
    Board(const std::string&);

    typedef char Row[3];

    size_t hash() const;
    const Row& operator[](const size_t) const;
    bool moveTile(Direction);
    bool solved() const;
};

#endif
