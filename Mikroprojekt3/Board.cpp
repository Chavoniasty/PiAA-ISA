#include "Board.h"


Board::Board(int tempSize, int tempPoints) {
    size = tempSize;
    fields = new char *[tempSize];
    for (int i = 0; i < size; i++) {
        fields[i] = new char[tempSize];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fields[i][j] = ' ';
        }
    }
    pointsToWin = tempPoints;
    emptyFields = tempSize * tempSize;
}

void Board::gameStart() {
    while (true) {
        displayBoard();
        noughtMove();
        if (checkForWinner('O')) {
            std::cout << "Naughts' won!";
            break;
        }
        displayBoard();
        crossMove();
        if (checkForWinner('X')) {
            std::cout << "Crosses' won!";
            break;
        }
    }
}

void Board::displayBoard() const {
    system("cls");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << fields[i][j];
        }
        std::cout << std::endl;
    }
}

bool Board::checkForWinner(char symbol) const {
    int counter = 0;
    // horizontal check
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fields[i][j] == symbol) {
                counter++;
                if (counter == pointsToWin) {
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    // vertical check
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fields[j][i] == symbol) {
                counter++;
                if (counter == pointsToWin) {
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    // up left to down right check
    for (int i = 0; i < size; i++) {
        if (fields[i][i] == symbol) {
            counter++;
            if (counter == pointsToWin) {
                return true;
            }
        } else {
            counter = 0;
        }
    }
    // up right to down left check
    int j = size - 1;
    for (int i = 0; i < size; i++) {
        if (fields[i][j] == symbol) {
            j--;
            counter++;
            if (counter == pointsToWin) {
                return true;
            }
        } else {
            counter = 0;
        }
    }
    return false;
}

void Board::noughtMove() {
    std::cout << "Insert row number:";
    int rowNum;
    std::cin >> rowNum;
    rowNum--;
    std::cout << "Insert column number:";
    int colNum;
    std::cin >> colNum;
    colNum--;
    if (fields[rowNum][colNum] == ' ') {
        fields[rowNum][colNum] = 'O';
    }
    emptyFields--;
}

void Board::crossMove() {
    std::cout << "Insert row number:";
    int rowNum;
    std::cin >> rowNum;
    rowNum--;
    std::cout << "Insert column number:";
    int colNum;
    std::cin >> colNum;
    colNum--;
    if (fields[rowNum][colNum] == ' ') {
        fields[rowNum][colNum] = 'X';
    }
    emptyFields--;
}

void Board::crossMove(int rowNum, int colNum) {
    if (fields[rowNum][colNum] == ' ') {
        fields[rowNum][colNum] = 'X';
    }
    emptyFields--;
}