#include "Board.h"

Board::Board(int tempSize){
    size = tempSize;
    fields = new char*[tempSize];
    for(int i = 0; i < size; i++){
        fields[i] = new char[tempSize];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fields[i][j] = ' ';
        }
    }
}

void Board::gameStart() const {
    while(1){
        this->displayBoard();
        this->noughtMove();
        if(checkForWinner('o')){
            std::cout << "Naughts' won!";
            break;
        }
        this->displayBoard();
        this->crossMove();
        if(checkForWinner('x')){
            std::cout << "Crosses' won!";
            break;
        }
    }
}

void Board::displayBoard() const{
    system("cls");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << fields[i][j];
        }
        std::cout << std::endl;
    }
}

bool Board::checkForWinner(char symbol) const{
    this->displayBoard();
    for(int i = 0; i < size; i++){
        int counter = 0;
        for(int j = 0; j<size; j++){
            if(fields[i][j] == symbol){
                counter++;
                if(counter == size){
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    for(int i = 0; i < size; i++){
        int counter = 0;
        for(int j = 0; j<size; j++){
            if(fields[j][i] == symbol){
                counter++;
                if(counter == size){
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j ++){
            int counter = 0;
            if(fields[i][j] == symbol){
                counter++;
                if(counter == size) {
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    for(int i = size - 1; i >= 0; i--){
        for(int j = 0; j < size; j++){
            int counter = 0;
            if(fields[i][j] == symbol){
                counter++;
                if(counter == size){
                    return true;
                }
            } else {
                counter = 0;
            }
        }
    }
    return false;
}

void Board::noughtMove() const{
    std::cout <<"Insert row number:";
    int rowNum;
    std::cin >> rowNum;
    rowNum--;
    std::cout <<"Insert column number:";
    int colNum;
    std::cin >> colNum;
    colNum--;
    if(fields[rowNum][colNum] == ' '){
        fields[rowNum][colNum] = 'o';
    }
}

void Board::crossMove() const {
    std::cout <<"Insert row number:";
    int rowNum;
    std::cin >> rowNum;
    rowNum--;
    std::cout <<"Insert column number:";
    int colNum;
    std::cin >> colNum;
    colNum--;
    if(fields[rowNum][colNum] == ' '){
        fields[rowNum][colNum] = 'x';
    }
}