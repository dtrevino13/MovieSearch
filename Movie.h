#ifndef ULTIMATEMOVIESEARCH_MOVIE_H
#define ULTIMATEMOVIESEARCH_MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie{
    string title;
    string genre;
    string year;
    string id;
public:
    Movie();
    Movie(string t, string g, string y, string i);
    string getTitle();
    string getYear();
    string getGenre();
    string getId();
};

#endif //ULTIMATEMOVIESEARCH_MOVIE_H
