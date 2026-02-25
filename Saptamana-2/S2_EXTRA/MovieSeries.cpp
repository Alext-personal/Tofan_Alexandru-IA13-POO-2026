#include "MovieSeries.h"
#include <stdio.h>
void MovieSeries::init()
{
    this -> count = 0;
    for(int i = 0; i < 16; i++)
        movies[i] = nullptr;
}

void MovieSeries::add(Movie* movie)
{
    if(this -> count >= 16)
        return;
    movies[this -> count] = movie;
    this -> count++;
}

void MovieSeries::print()
{
    for(int i = 0; i < this -> count; i++)
    {
        printf("Name: %s\n",movies[i]->get_name());
        printf("Release Year: %d\n",movies[i]->get_year());
        printf("Score: %f\n",movies[i]->get_score());
        printf("Length: %d\n",movies[i]->get_length());
    }
}

void MovieSeries::sort()
{
    for(int i = 0; i < this -> count - 1; i++)
        for(int j = i + 1; j < this -> count; j++)
            if(Movie::movie_compare_passed_years(*movies[i],*movies[j]) > 0)
            {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
}
