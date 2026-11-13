#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void display() const;
    bool placeMark(int position, char player);
    bool isFull() const;
    bool checkWinner(char player) const;
    bool isValidMove(int position) const;
    char getCell(int position) const;

private:
    char cells[9];
};

#endif
