#ifndef MIKROPROJEKT3_GAMEWITHAI_H
#define MIKROPROJEKT3_GAMEWITHAI_H

#include "Board.h"4
#include "AI.h"

class GameWithAI {
public:
    GameWithAI(int boardSize, int tempPoints);

    void startGameWithAI();

private:
    AI enemy;
    Board gameBoard;
};

#endif //MIKROPROJEKT3_GAMEWITHAI_H
