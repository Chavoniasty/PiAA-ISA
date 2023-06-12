#include "AI.h"

AI::AI() {};

bool AI::isMoveLeft(Board &tempBoard) {
    return tempBoard.emptyFields != 0;
}

int AI::calculate(Board &tempBoard) const {
    if (tempBoard.checkForWinner(AIsymbol)) {
        return 3000;
    } else if (tempBoard.checkForWinner(playerSymbol)) {
        return -100;
    }
    return 0;
}


int AI::minmax(Board &tempBoard, int depth, bool isMax, int alpha, int beta) {
    int score = calculate(tempBoard);
    if (score == 3000 || depth == 10) {
        return score - depth;
    }
    if (score == -100 || depth == 10) {
        return score + depth;
    }
    if (!isMoveLeft(tempBoard)) {
        return 0;
    }
    if (isMax) {
        int best = 1000;
        for (int i = 0; i < tempBoard.size; i++) {
            for (int j = 0; j < tempBoard.size; j++) {
                if (tempBoard.fields[i][j] == ' ') {
                    tempBoard.fields[i][j] = AIsymbol;
                    int temp = minmax(tempBoard, depth + 1, false, alpha, beta);
                    best = std::max(best, temp);
                    tempBoard.fields[i][j] = ' ';
                    alpha = std::max(alpha, best);
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < tempBoard.size; i++) {
            for (int j = 0; j < tempBoard.size; j++) {
                if (tempBoard.fields[i][j] == ' ') {
                    tempBoard.fields[i][j] = playerSymbol;
                    int temp = minmax(tempBoard, depth + 1, true, alpha, beta);
                    best = std::min(best, temp);
                    tempBoard.fields[i][j] = ' ';
                    beta = std::min(beta, best);
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
        }
        return best;
    }
}

void AI::findBestMove(Board &tempBoard) {
    int bestVal = -1000;
    Move bestMove{};
    bestMove.rowNum = -1;
    bestMove.colNum = -1;
    for (int i = 0; i < tempBoard.size; i++) {
        for (int j = 0; j < tempBoard.size; j++) {
            if (tempBoard.fields[i][j] == ' ') {
                tempBoard.fields[i][j] = AIsymbol;
                int moveVal = minmax(tempBoard, 0, false, -100, 100);
                std::cout << "x: " << i + 1 << " ,y: " << j + 1 << " | POINTS: " << moveVal << std::endl;
                tempBoard.fields[i][j] = ' ';
                if (moveVal >= bestVal) {
                    bestMove.rowNum = i;
                    bestMove.colNum = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    tempBoard.crossMove(bestMove.rowNum, bestMove.colNum);
}