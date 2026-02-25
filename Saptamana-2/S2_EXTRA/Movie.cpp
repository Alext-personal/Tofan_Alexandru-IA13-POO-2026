#define DEFAULTSCORE 5
#include "Movie.h"
#include <cstring>
#include <time.h>
void Movie::set_name(const char* newName)
{
    this -> name = new char[strlen(newName)];
    strcpy(this -> name, newName);
}

char* Movie::get_name()
{
    return this -> name;
}

void Movie::set_year(int newYear)
{
    this -> releaseYear = newYear;
}
int Movie::get_year()
{
    return this -> releaseYear;
}

void Movie::set_score(double newScore)
{
    if (newScore < 1.0 || newScore > 10.0)
    {
        this -> IMDBScore = DEFAULTSCORE;
        return;
    }
    this -> IMDBScore = newScore;
}
double Movie::get_score()
{
    return this -> IMDBScore;
}

void Movie::set_length(int newLength)
{
    this -> length = newLength;
}
int Movie::get_length()
{
    return this -> length;
}

int Movie::get_passed_years()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int currentYear = timePtr->tm_year + 1900;
    return currentYear - this -> releaseYear;
}

int Movie::movie_compare_name(Movie a, Movie b) {
    return strcmp(a.get_name(), b.get_name());
}

int Movie::movie_compare_year(Movie a, Movie b) {
    int yearA = a.get_year();
    int yearB = b.get_year();
    if (yearA < yearB)
        return -1;
    if (yearA > yearB)
        return 1;
    return 0;
}

int Movie::movie_compare_score(Movie a, Movie b) {
    double scoreA = a.get_score();
    double scoreB = b.get_score();
    if (scoreA < scoreB)
        return -1;
    if (scoreA > scoreB)
        return 1;
    return 0;
}

int Movie::movie_compare_length(Movie a, Movie b) {
    int lengthA = a.get_length();
    int lengthB = b.get_length();
    if (lengthA < lengthB)
        return -1;
    if (lengthA > lengthB)
        return 1;
    return 0;
}

int Movie::movie_compare_passed_years(Movie a, Movie b)
{
    int passedA = a.get_passed_years();
    int passedB = b.get_passed_years();
    if (passedA < passedB)
        return -1;
    if (passedA > passedB)
        return 1;
    return 0;
}
