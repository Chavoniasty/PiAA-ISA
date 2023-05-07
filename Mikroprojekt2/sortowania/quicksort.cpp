#include "quicksort.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<Movie> &moviesVec, int first, int last) {
    while (first < last) {
        int pivot = moviesVec.at((first + last) / 2).rate;
        int a = first;
        int b = last;
        while (a <= b) {
            while (moviesVec.at(a).rate < pivot) {
                a++;
            }
            while (moviesVec.at(b).rate > pivot) {
                b--;
            }
            if (a <= b) {
                swap(moviesVec[a], moviesVec[b]);
                a++;
                b--;
            }
        }
        if (b - first < last - a) {
            quicksort(moviesVec, first, b);
            first = a;
        } else {
            quicksort(moviesVec, a, last);
            last = b;
        }
    }
}