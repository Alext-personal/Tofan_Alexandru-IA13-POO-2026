#pragma once

class Movie
{
    char* name;
    int releaseYear;
    double IMDBScore;
    int length;
public:
    void set_length(int newLength);
    void set_name(const char* newName);
    void set_score(double newScore);
    void set_year(int newYear);
    double get_score();
    char* get_name();
    int get_passed_years();
    int get_year();
    int get_length();
    static int movie_compare_name(Movie a, Movie b);
    static int movie_compare_year(Movie a, Movie b);
    static int movie_compare_score(Movie a, Movie b);
    static int movie_compare_length(Movie a, Movie b);
    static int movie_compare_passed_years(Movie a, Movie b);
   
};
