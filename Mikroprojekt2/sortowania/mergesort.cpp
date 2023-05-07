#include "mergesort.h"

using namespace std;

void merge(vector<Movie> &moviesVec, int first, int mid, int last) {
    vector<Movie> temp;
    int a = first;
    int b = mid + 1;
    while (a <= mid && b <= last) {
        if (moviesVec.at(a).rate <= moviesVec.at(b).rate) {
            temp.push_back(moviesVec.at(a));
            ++a;
        } else {
            temp.push_back(moviesVec.at(b));
            ++b;
        }
    }
    while (a <= mid) {
        temp.push_back(moviesVec.at(a));
        a++;
    }
    while (b <= last) {
        temp.push_back(moviesVec.at(b));
        b++;
    }
    for (int i = first; i <= last; ++i) {
        moviesVec.at(i) = temp.at(i - first);
    }
}

void mergeSort(vector<Movie> &moviesVec, int first, int last) {
    if (first >= last) {
        return;
    }
    auto mid = first + (last - first) / 2;
    mergeSort(moviesVec, first, mid);
    mergeSort(moviesVec, mid + 1, last);
    merge(moviesVec, first, mid, last);
}