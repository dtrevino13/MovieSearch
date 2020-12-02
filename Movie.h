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
    Movie(string t, string g, string y, string i);
    string getTitle();
    string getYear();
    string getGenre();
};

Movie::Movie(string t, string g, string y, string i) {
    title = t;
    genre = g;
    year = y;
    id = i;
}

string Movie::getTitle() {
    return title;
}

string Movie::getYear() {
    return year;
}

string Movie::getGenre() {
    return genre;
}

#endif //ULTIMATEMOVIESEARCH_MOVIE_H
