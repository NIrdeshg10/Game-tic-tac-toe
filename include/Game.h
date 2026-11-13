#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
    Game();
    void start();

private:
    Board board;
    char currentPlayer;
    bool gameOver;

    void playTurn();
    void switchPlayer();
    void displayStatus() const;
    bool checkForWinner();
    bool checkForTie();
};

#endif
