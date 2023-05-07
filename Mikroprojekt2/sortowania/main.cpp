#include "Movie.h"
#include "bucketsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define size1 10000
#define size2 100000
#define size3 500000
#define size4 1000000

vector<Movie> loadData()
{
    vector<Movie> moviesVec;
    string line;
    string tempId;
    string tempTitle;
    string tempRate;
    ifstream IMDbData("projekt2_dane.csv");
    getline(IMDbData, line);
    for (int i = 0; i < size4; i++)
    {
        getline(IMDbData, tempId, ',');
        getline(IMDbData, tempTitle, ',');
        while (tempTitle.front() == '"')
        {
            string quotesTitle;
            if (tempTitle.back() == '"')
            {
                break;
            }
            getline(IMDbData, quotesTitle, ',');
            tempTitle += ',' + quotesTitle;
        }
        getline(IMDbData, tempRate);
        if (!tempRate.empty())
        {
            int tempRateINT = stoi(tempRate);
            Movie tempMovie(tempId, tempTitle, tempRateINT);
            moviesVec.push_back(tempMovie);
        }
    }
    return moviesVec;
}

vector<Movie> deleteBadData(vector<Movie> moviesVec)
{
    for (int i = 0; i < moviesVec.size(); i++)
    {
        if (moviesVec.at(i).rate == 0)
        {
            moviesVec.erase(moviesVec.begin() + i);
        }
    }
    return moviesVec;
}

int main()
{
    vector<Movie> moviesVec(loadData());
    moviesVec = deleteBadData(moviesVec);
    auto start = chrono::high_resolution_clock::now();
    //  CHOOSE SORTING ALGORITHM BY UNCOMMENTING SELECTED LINE
    // quicksort(moviesVec, 0, moviesVec.size() - 1);
    // bucketSort(moviesVec);
    // mergeSort(moviesVec, 0, moviesVec.size() - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Duration: " << duration.count();
}