#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "Movie.h"

using namespace std;

void storeMovies(unordered_map<string,vector<Movie>>& titles,unordered_map<string,vector<Movie>>& genres,unordered_map<string,vector<Movie>>& years){
    ifstream inFile("data.tsv");
    string title,genre,year,ID;
    string type;
    string throwAway;
    string line;

    getline(inFile,line); //for header
    if(inFile.is_open()){
        while(getline(inFile,line)){
            istringstream stream(line);

            getline(stream,ID,'\t');

            //check if input is a movie,short,video
            getline(stream,type,'\t');

            getline(stream,title,'\t');

            //skip originalTitle & isAdult
            getline(stream,throwAway,'\t');
            getline(stream,throwAway,'\t');

            //get year
            getline(stream,year,'\t');
            if(year=="\\N")
                year="unknown";

            //skip endYear & runtimeMinutes
            getline(stream,throwAway,'\t');
            getline(stream,throwAway,'\t');

            //get genre
            getline(stream,genre,',');
            if(genre=="\\N")
                genre="unknown";
            if(type=="movie" || type=="short" || type=="video") {
                titles[title].push_back(Movie(title, genre, year, ID));
                genres[genre].push_back(Movie(title, genre, year, ID));
                years[year].push_back(Movie(title, genre, year, ID));
            }
        }
    }


}

int main() {
    unordered_map<string,vector<Movie>> titles;
    unordered_map<string,vector<Movie>> genres;
    unordered_map<string,vector<Movie>> years;

    storeMovies(titles, genres, years);

    for(auto iter=titles.begin();iter!=titles.end();iter++){
        cout<<iter->first<<endl;

    }


}
