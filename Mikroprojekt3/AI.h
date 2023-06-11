#ifndef MIKROPROJEKT3_AI_H
#define MIKROPROJEKT3_AI_H

#include <iostream>
#include "Board.h"

struct Move {
    int rowNum, colNum;
};

class AI {
public:
    char AIsymbol = 'X';
    char playerSymbol = 'O';

    AI();

    bool isMoveLeft(Board &tempBoard);

    int calculate(Board &tempBoard) const;

    int minmax(Board &tempBoard, int depth, bool isMax, int alpha, int beta);

    Move findBestMove(Board &tempBoard);
};


#endif
