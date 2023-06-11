#include "GameWithAI.h"

GameWithAI::GameWithAI(int boardSize, int tempPoints) : gameBoard(boardSize, tempPoints), enemy() {
}

void GameWithAI::startGameWithAI() {
    while (!gameBoard.emptyFields == 0) {
        gameBoard.displayBoard();
        gameBoard.noughtMove();
        if (gameBoard.checkForWinner('O')) {
            gameBoard.displayBoard();
            std::cout << "Naughts won!";
            break;
        }
        gameBoard.displayBoard();
        enemy.findBestMove(gameBoard);
        if (gameBoard.checkForWinner('X')) {
            gameBoard.displayBoard();
            std::cout << "Crosses won!";
            break;
        }
    }
}