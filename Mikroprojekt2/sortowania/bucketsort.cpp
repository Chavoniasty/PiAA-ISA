#include "Movie.h"

using namespace std;

void bucketSort(vector<Movie> &moviesVec) {
    int size = moviesVec.size();
    int min = moviesVec.at(0).rate;
    int max = moviesVec.at(0).rate;

    for (int i = 1; i < size; i++) {
        if (moviesVec.at(i).rate > max) {
            max = moviesVec.at(i).rate;
        }
        if (moviesVec.at(i).rate < min) {
            min = moviesVec.at(i).rate;
        }
    }
    int length = max - min + 1;
    vector<Movie> *bucket = new vector<Movie>[length];
    for (int i = 0; i < length; i++) {
        bucket[i] = vector<Movie>();
    }
    for (int i = 0; i < size; i++) {
        bucket[moviesVec.at(i).rate - min].push_back(moviesVec.at(i));
    }
    int a = 0;
    for (int i = 0; i < length; i++) {
        int tempSize = bucket[i].size();
        if (tempSize > 0) {
            for (int j = 0; j < tempSize; j++) {
                moviesVec.at(a) = bucket[i][j];
                a++;
            }
        }
    }
}