#include "Game.h"

#include <iostream>

Game::Game() : currentPlayer('X'), gameOver(false) {}

void Game::start() {
    while (!gameOver) {
        displayStatus();
        board.display();
        playTurn();

        if (checkForWinner()) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
            board.display();
            return;
        }

        if (checkForTie()) {
            std::cout << "It's a tie!\n";
            board.display();
            gameOver = true;
            return;
        }

        switchPlayer();
    }
}

void Game::playTurn() {
    int move;
    std::cout << "Player " << currentPlayer << ", choose a position (1-9): ";
    std::cin >> move;

    while (!board.placeMark(move, currentPlayer)) {
        std::cout << "Invalid move. Please choose an empty position from 1 to 9: ";
        std::cin >> move;
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Game::displayStatus() const {
    std::cout << "\nCurrent board:\n";
}

bool Game::checkForWinner() {
    return board.checkWinner(currentPlayer);
}

bool Game::checkForTie() {
    return board.isFull();
}
