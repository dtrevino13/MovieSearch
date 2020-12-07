#include "Movie.h"

Movie::Movie() {}
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

string Movie::getId() {
    return id;
}