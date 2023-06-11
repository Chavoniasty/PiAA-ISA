#include <iostream>
#include "GameWithAI.h"

int main() {
    std::cout << "Insert board size: ";
    int boardSize;
    std::cin >> boardSize;
    std::cout << "How many points player need to have for winning:";
    int tempPoints;
    std::cin >> tempPoints;
    GameWithAI game = GameWithAI(boardSize, tempPoints);
    game.startGameWithAI();
}