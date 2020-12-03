#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include "Movie.h"
using namespace std;

#ifndef ULTIMATEMOVIESEARCH_SEARCH_H
#define ULTIMATEMOVIESEARCH_SEARCH_H

//Search for title from map of titles
vector<Movie> searchTitle(string title, unordered_map<string, Movie> myMap){
    vector<Movie> movieList;
    for(auto itr : myMap){
        if(itr.first.find(title) != string::npos)
            movieList.push_back(itr.second);
    }
    return movieList;
}

//Search for year from map of years
vector<Movie> searchYear(string year, unordered_map<string, Movie> myMap){
    vector<Movie> movieList;
    for(auto itr : myMap){
        if(myMap.find(year) != myMap.end())
            movieList.push_back(itr.second);
    }
    return movieList;
}

//Search for genre from map of genres
vector<Movie> searchGenre(string genre, unordered_map<string, Movie> myMap){
    vector<Movie> movieList;
    for(auto itr : myMap){
        if(myMap.find(genre) != myMap.end())
            movieList.push_back(itr.second);
    }
    return movieList;
}

//Search for title, year, and genre from map of titles
vector<Movie> searchTYG(string title, string year, string genre, unordered_map<string, Movie> mapTitle){
    vector<Movie> movieList = searchTitle(title,mapTitle);
    for(int i=0; i<movieList.size();i++){
        if(movieList[i].getYear()!=year || movieList[i].getGenre()!=genre) {
            movieList.erase(movieList.begin() + i);
            i--;
        }
    }
    return movieList;
}

//Search for title and year from map of titles
vector<Movie> searchTY(string title, string year, unordered_map<string, Movie> mapTitle){
    vector<Movie> movieList = searchTitle(title,mapTitle);
    for(int i=0; i<movieList.size();i++){
        if(movieList[i].getYear()!=year){
            movieList.erase(movieList.begin() + i);
            i--;
        }
    }
    return movieList;
}

//Search for title and genre from map of titles
vector<Movie> searchTG(string title, string genre, unordered_map<string, Movie> mapTitle){
    vector<Movie> movieList = searchTitle(title,mapTitle);
    for(int i=0; i<movieList.size();i++){
        if(movieList[i].getGenre()!=genre){
            movieList.erase(movieList.begin() + i);
            i--;
        }
    }
    return movieList;
}

//Search for year and genre from map of years
vector<Movie> searchYG(string year, string genre, unordered_map<string, Movie> mapYear){
    vector<Movie> movieList = searchYear(year,mapYear);
    for(int i=0; i<movieList.size();i++){
        if(movieList[i].getGenre()!=genre){
            movieList.erase(movieList.begin() + i);
            i--;
        }
    }
    return movieList;
}

#endif //ULTIMATEMOVIESEARCH_SEARCH_H
