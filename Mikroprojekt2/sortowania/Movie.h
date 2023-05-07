#pragma once
#include <iostream>
#include <string>

using namespace std;

class Movie {
public:
    string id;
    string title;
    int rate;

    Movie(string tempId, string tempTitle, int tempRate);
};
