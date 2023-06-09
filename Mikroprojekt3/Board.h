#ifndef MIKROPROJEKT3_BOARD_H
#define MIKROPROJEKT3_BOARD_H

#include <iostream>

class Board {
public:
    int size;
    char **fields;
    int pointsToWin;

    explicit Board(int tempSize, int tempPoints);

    void displayBoard() const;

    void gameStart() const;

    [[nodiscard]] bool checkForWinner(char symbol) const;

    void noughtMove() const;

    void crossMove() const;
};

#endif
