#ifndef GAME_H
#define GAME_H

#include "Board.h"
// Controls the Tic-Tac-Toe game and player turns.
class Game {
public:
  // Creates a new game.
    Game();
     // Starts the game.
    void start();

private:
   // Stores the game board.
    Board board;

    // Keeps track of the current player.
    char currentPlayer;

    // Checks whether the game is over.
    bool gameOver;

    // Lets the current player make a move.
    void playTurn();

    // Switches between player X and player O.
    void switchPlayer();

    // Displays the current game status.
    void displayStatus() const;

    // Checks whether a player has won.
    bool checkForWinner();

    // Checks whether the game is a tie.
    bool checkForTie();
};

#endif
