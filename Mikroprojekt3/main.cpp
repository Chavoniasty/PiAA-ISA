#include <iostream>
#include "Board.h"

int main() {
    std::cout << "Insert board size: ";
    int boardSize;
    std::cin >> boardSize;
    Board gameBoard(boardSize);
    gameBoard.gameStart();
}