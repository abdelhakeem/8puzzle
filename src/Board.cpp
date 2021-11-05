#include <stdexcept>

#include "Board.h"

Board::Board(const std::string& boardstr) {
    if (boardstr.size() != 9) {
        throw std::domain_error("Invalid board configuration");
    }

    int pos = 0;
    bool exists[9] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char cur = boardstr[pos++];

            if (cur < '0' || cur > '8' || exists[cur - '0']) {
                throw std::domain_error("Invalid board configuration");
            }

            if (cur == '0') {
                emptyTile = std::make_pair(i, j);
            }

            board[i][j] = cur;
            exists[cur - '0'] = true;
        }
    }
}

size_t Board::hash() const {
    size_t key = 0;

    for (const Board::Row& row : board) {
        for (char tile : row) {
            key = key * 10 + (tile - '0');
        }
    }

    return key;
}

const Board::Row& Board::operator[](const size_t row) const {
    return board[row];
}

bool Board::moveTile(Direction dir) {
    int x = emptyTile.first;
    int y = emptyTile.second;

    switch (dir) {
        case Direction::Up:
            if (x == 0) {
                return false;
            } else {
                board[x][y] = board[x-1][y];
                x--;
            }
            break;
        case Direction::Down:
            if (x == 2) {
                return false;
            } else {
                board[x][y] = board[x+1][y];
                x++;
            }
            break;
        case Direction::Right:
            if (y == 2) {
                return false;
            } else {
                board[x][y] = board[x][y+1];
                y++;
            }
            break;
        case Direction::Left:
            if (y == 0) {
                return false;
            } else {
                board[x][y] = board[x][y-1];
                y--;
            }
            break;
    }

    board[x][y] = '0';
    emptyTile = std::make_pair(x, y);

    return true;
}

bool Board::solved() const {
    char cur = '0';

    for (const Board::Row& row : board) {
        for (char tile : row) {
            if (tile != cur++) {
                return false;
            }
        }
    }

    return true;
}
