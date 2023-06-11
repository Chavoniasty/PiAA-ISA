#include "AI.h"

AI::AI() {};

bool AI::isMoveLeft(Board &tempBoard) {
    return tempBoard.emptyFields != 0;
}

int AI::calculate(Board &tempBoard) const {
    if (tempBoard.checkForWinner(AIsymbol)) {
        return 10;
    } else if (tempBoard.checkForWinner(playerSymbol)) {
        return -10;
    }
    return 0;
}


int AI::minmax(Board &tempBoard, int depth, bool isMax, int alpha, int beta) {
    int score = calculate(tempBoard);
    if (score == 10 || score == -10) {
        return score;
    }
    if (!isMoveLeft(tempBoard)) {
        return 0;
    }
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < tempBoard.size; i++) {
            for (int j = 0; j < tempBoard.size; j++) {
                if (tempBoard.fields[i][j] == ' ') {
                    tempBoard.fields[i][j] = AIsymbol;
                    best = std::max(best, minmax(tempBoard, depth + 1, false, alpha, beta));
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
                    best = std::min(best, minmax(tempBoard, depth + 1, true, alpha, beta));
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
                int moveVal = minmax(tempBoard, 0, false, -1000, 1000);
                tempBoard.fields[i][j] = ' ';
                if (moveVal > bestVal) {
                    bestMove.rowNum = i;
                    bestMove.colNum = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    tempBoard.crossMove(bestMove.rowNum, bestMove.colNum);
}