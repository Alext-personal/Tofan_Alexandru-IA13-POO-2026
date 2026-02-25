#pragma once
#include "Movie.h"
class MovieSeries
{   
    int count;
    Movie* movies[16];
public:
    void init();
    void add(Movie* movie);
    void print();
    void sort();
};
