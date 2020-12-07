#ifndef ULTIMATEMOVIESEARCH_GRAPHICS_H
#define ULTIMATEMOVIESEARCH_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Button.h"
#include "Movie.h"
using std::string;
using std::vector;

void DrawMovies(vector<Movie>& movies, int offset, sf::RenderWindow& window){
    sf::Font font;
    font.loadFromFile("Font/Roboto-Black.ttf");
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::Black);
    for (int i = 0; i < 10; i++) {
        if (i + offset == movies.size())
            break;
        Movie currMovie = movies[offset + i];
        text.setString(currMovie.getTitle() + ", " + currMovie.getYear() + ", " + currMovie.getGenre());
        text.setPosition(sf::Vector2f(50, 100 + 20 * i));
        window.draw(text);
    }
}

#endif //ULTIMATEMOVIESEARCH_GRAPHICS_H
