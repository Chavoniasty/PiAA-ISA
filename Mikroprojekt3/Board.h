#ifndef MIKROPROJEKT3_BOARD_H
#define MIKROPROJEKT3_BOARD_H

#include <iostream>

class Board {
public:
    int size;
    char **fields;
    int pointsToWin;
    int emptyFields;

    Board(int tempSize, int tempPoints);

    void displayBoard() const;

    void gameStart();

    bool checkForWinner(char symbol) const;

    void noughtMove();

    void crossMove();

    void crossMove(int rowNum, int colNum);

    void noughtMove(int rowNum, int colNum);
};

#endif
