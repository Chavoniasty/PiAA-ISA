#include <algorithm>
#include <iostream>
#include <vector>

#include "Movie.h"
using namespace std;
void merge(vector<Movie> &moviesVec, int first, int mid, int last);

void mergeSort(vector<Movie> &moviesVec, int first, int last);