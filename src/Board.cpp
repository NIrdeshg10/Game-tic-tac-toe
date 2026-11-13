#include "Board.h"

#include <iostream>
#include <stdexcept>

Board::Board() {
    for (int i = 0; i < 9; ++i) {
        cells[i] = static_cast<char>('1' + i);
    }
}

void Board::display() const {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << "   ";
        for (int col = 0; col < 3; ++col) {
            int index = row * 3 + col;
            std::cout << cells[index];
            if (col < 2) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
        if (row < 2) {
            std::cout << "  -----------\n";
        }
    }
    std::cout << "\n";
}

bool Board::placeMark(int position, char player) {
    if (!isValidMove(position)) {
        return false;
    }

    cells[position - 1] = player;
    return true;
}

bool Board::isFull() const {
    for (int i = 0; i < 9; ++i) {
        if (cells[i] >= '1' && cells[i] <= '9') {
            return false;
        }
    }
    return true;
}

bool Board::checkWinner(char player) const {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (const auto& pattern : winPatterns) {
        if (cells[pattern[0]] == player &&
            cells[pattern[1]] == player &&
            cells[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool Board::isValidMove(int position) const {
    if (position < 1 || position > 9) {
        return false;
    }
    return cells[position - 1] >= '1' && cells[position - 1] <= '9';
}

char Board::getCell(int position) const {
    if (position < 1 || position > 9) {
        throw std::out_of_range("Cell position is out of range.");
    }
    return cells[position - 1];
}
