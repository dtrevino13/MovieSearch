//unfinished: We need to implement the search functionality in state 1 (the search screen).
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Button.h"
#include "Movie.h"
using std::string;
using std::vector;
void DrawMovies(vector<Movie>& movies, int offset, sf::RenderWindow& window) {
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
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "Movie Search");

    sf::Font font;
    font.loadFromFile("Font/Roboto-Black.ttf");
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);

    sf::Texture search;
    sf::Texture favorites;
    sf::Texture checkbox;
    sf::Texture checkedbox;
    sf::Texture next;
    sf::Texture startOver;
    sf::Texture nextTen;
    sf::Texture prevTen;
    sf::Texture like;
    sf::Texture titleSearch;
    sf::Texture yearSearch;
    sf::Texture genreSearch;

    search.loadFromFile("Images/Search.png");
    favorites.loadFromFile("Images/Favorites.png");
    checkbox.loadFromFile("Images/Box.png");
    checkedbox.loadFromFile("Images/Box_Checked.png");
    next.loadFromFile("Images/Next.png");
    startOver.loadFromFile("Images/Start_Over.png");
    nextTen.loadFromFile("Images/Next_Ten.png");
    prevTen.loadFromFile("Images/Prev_Ten.png");
    like.loadFromFile("Images/Like.png");
    titleSearch.loadFromFile("Images/Title_Search.png");
    yearSearch.loadFromFile("Images/Year_Search.png");
    genreSearch.loadFromFile("Images/Genre_Search.png");

    sf::Sprite searchSprite = sf::Sprite(search);
    sf::Sprite favoritesSprite = sf::Sprite(favorites);
    sf::Sprite boxSprite0 = sf::Sprite(checkbox);
    sf::Sprite boxSprite1 = sf::Sprite(checkbox);
    sf::Sprite boxSpriteChecked0 = sf::Sprite(checkedbox);
    sf::Sprite boxSpriteChecked1 = sf::Sprite(checkedbox);
    sf::Sprite nextSprite = sf::Sprite(next);
    sf::Sprite startOverSprite = sf::Sprite(startOver);
    sf::Sprite nextTenSprite = sf::Sprite(nextTen);
    sf::Sprite prevTenSprite = sf::Sprite(prevTen);
    sf::Sprite likeSprite = sf::Sprite(like);
    sf::Sprite titleSearchSprite = sf::Sprite(titleSearch);
    sf::Sprite yearSearchSprite = sf::Sprite(yearSearch);
    sf::Sprite genreSearchSprite = sf::Sprite(genreSearch);

    searchSprite.setPosition(sf::Vector2f(600, 300));
    favoritesSprite.setPosition(sf::Vector2f(525, 0));
    boxSprite0.setPosition(sf::Vector2f(100, 150));
    boxSprite1.setPosition(sf::Vector2f(100, 250));
    boxSpriteChecked0.setPosition(sf::Vector2f(100, 150));
    boxSpriteChecked1.setPosition(sf::Vector2f(100, 250));
    nextSprite.setPosition(sf::Vector2f(600, 300));
    startOverSprite.setPosition(sf::Vector2f(600, 300));
    nextTenSprite.setPosition(sf::Vector2f(600, 100));
    prevTenSprite.setPosition(sf::Vector2f(600, 200));
    likeSprite.setPosition(sf::Vector2f(0, 0));
    titleSearchSprite.setPosition(sf::Vector2f(50, 50));
    yearSearchSprite.setPosition(sf::Vector2f(500, 200));
    genreSearchSprite.setPosition(sf::Vector2f(130, 200));

    int state = 0;
    /*states:
    0 - Choose Sorting Method
    1 - Filter Selection
    2 - Display Results
    */
    //state 0 variables:
    Button nextButton(nextSprite.getGlobalBounds());
    Button quickSort(boxSprite0.getGlobalBounds());
    Button mergeSort(boxSprite1.getGlobalBounds());
    //state 1 variables:
    Button searchButton(searchSprite.getGlobalBounds());
    Button favoritesButton(favoritesSprite.getGlobalBounds());
    Button titleSearchButton(titleSearchSprite.getGlobalBounds());
    Button genreSearchButton(genreSearchSprite.getGlobalBounds());
    Button yearSearchButton(yearSearchSprite.getGlobalBounds());
    string genre = "";
    string title = "";
    string year = "";
    bool searched = false;
    bool enterTitle = false;
    bool enterYear = false;
    bool enterGenre = false;
    //state 2 variables:
    Button startOverButton(startOverSprite.getGlobalBounds());
    Button nextTenButton(nextTenSprite.getGlobalBounds());
    Button prevTenButton(prevTenSprite.getGlobalBounds());
    int offset = 0;
    //this vector is filled with test values. In the program, it would contain the sorted list of movies according to the search parameters.
    vector<Movie> movies = { Movie("Transformers", "Action", "2000", "50"), Movie("Alladin", "Fantasy", "2001", "51"), Movie("Borat", "Comedy", "2005", "52"), Movie("Borat 2", "Comedy", "2020", "53"), 
                            Movie("Once Upon a Time in Hollywood", "Drama", "2019", "54"), Movie("Avengers", "Action", "2015", "55"), Movie("Frozen", "Fantasy", "2010", "56"), Movie("Titanic", "Drama", "2000", "57"),
                            Movie("Avatar", "Action", "2008", "58"), Movie("Pulp Fiction", "Drama", "1980", "59"), Movie("Bill and Ted's Excellent Adventure", "Comedy", "1979", "60")};
    vector<Movie> favoriteMovies;



    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i Clicked;
        window.clear(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Clicked = sf::Mouse::getPosition(window);
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (enterGenre) {
                    if (event.text.unicode == 8) {
                        if (genre.size() > 0)
                            genre.pop_back();
                    }
                    else
                        genre.push_back(event.text.unicode);
                }
                if (enterTitle) {
                    if (event.text.unicode == 8) {
                        if (title.size() > 0)
                            title.pop_back();
                    }
                    else
                        title.push_back(event.text.unicode);
                }
                if (enterYear) {
                    if (event.text.unicode == 8) {
                        if (year.size() > 0)
                            year.pop_back();
                    }
                    else
                        year.push_back(event.text.unicode);
                }
            }
        }
        if (state == 0) {
            //first screen
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Regular);
            text.setCharacterSize(30);
            text.setPosition(275, 50);
            text.setString("Choose Sorting Method");
            window.draw(text);
            text.setPosition(200, 150);
            text.setString("Quick Sort");
            window.draw(text);
            text.setPosition(200, 250);
            text.setString("Merge Sort");
            window.draw(text);

            if (quickSort.clicked == true)
                window.draw(boxSpriteChecked0);
            else
                window.draw(boxSprite0);
            if (mergeSort.clicked == true)
                window.draw(boxSpriteChecked1);
            else
                window.draw(boxSprite1);
            window.draw(nextSprite);
            if (nextButton.Contains(Clicked) && (mergeSort.clicked || quickSort.clicked)) {
                state = 1;
                mergeSort.clicked = false;
                quickSort.clicked = false;
            }
            if (mergeSort.Contains(Clicked)) {
                mergeSort.Click();
                quickSort.clicked = false;
            }
            if (quickSort.Contains(Clicked)) {
                quickSort.Click();
                mergeSort.clicked = false;
            }
            //if mouse clicks inside of an unchecked checkbox, set that button to true, and the other one to false.
            //then, if mouse clicks inside of "next" button, the state changes to 1.
        }
        else if (state == 1) {
            //filter screen
            text.setStyle(sf::Text::Underlined);
            text.setCharacterSize(35);
            text.setPosition(515, 130);
            text.setFillColor(sf::Color::Black);
            text.setString("Year Released");
            window.draw(text);
            text.setPosition(200, 130);
            text.setString("Genre");
            window.draw(text);
            window.draw(titleSearchSprite);
            window.draw(yearSearchSprite);
            window.draw(genreSearchSprite);
            window.draw(searchSprite);
            window.draw(favoritesSprite);
            text.setStyle(sf::Text::Regular);
            text.setCharacterSize(20);
            text.setPosition(95, 55);
            if (title == "") {
                text.setString("Search Title");
                text.setFillColor(sf::Color::Color(128, 128, 128, 128));
            }
            else {
                text.setString(title);
                text.setFillColor(sf::Color::Black);
            }
            window.draw(text);

            text.setStyle(sf::Text::Regular);
            text.setCharacterSize(35);
            text.setPosition(533, 215);
            if (year == "") {
                text.setString("Enter Year");
                text.setFillColor(sf::Color::Color(128, 128, 128, 128));
            }
            else {
                text.setString(year);
                text.setFillColor(sf::Color::Black);
            }
            window.draw(text);
            text.setStyle(sf::Text::Regular);
            text.setCharacterSize(35);
            text.setPosition(160, 215);
            if (genre == "") {
                text.setString("Enter Genre");
                text.setFillColor(sf::Color::Color(128, 128, 128, 128));
            }
            else {
                text.setString(genre);
                text.setFillColor(sf::Color::Black);
            }
            window.draw(text);
            if (favoritesButton.Contains(Clicked)) {
                movies = favoriteMovies;
                state = 2;
            }
            if (searchButton.Contains(Clicked)) {
                if (title != "" && genre == "" && year == "") {
                    searched = true;
                    //movies = movies.sortbytitle()
                }
                if (title != "" && genre != "" && year == "") {
                    searched = true;
                    //movies = movies.sortby genre,title()
                }
                if (title != "" && genre != "" && year != "") {
                    searched = true;
                    //movies = movies.sortby title,genre,year()
                }
                if (title != "" && genre == "" && year != "") {
                    searched = true;
                    //movies = moves.sortby title, year()
                }
                if (title == "" && genre != "" && year != "") {
                    searched = true;
                    //movies = movies.sortby genre,year()
                }
                if (title == "" && genre != "" && year == "") {
                    searched = true;
                    //movies = movies.sortby genre()
                }
                if (title == "" && genre == "" && year != "") {
                    searched = true;
                    //movies = movies.sortby year()
                }
                if (title == "" && genre == "" && year == "") {
                    searched = false;
                }
                if(searched)
                    state = 2;
            }
            if (titleSearchButton.Contains(Clicked)) {
                enterTitle = true;
                enterGenre = false;
                enterYear = false;
            }
            if (yearSearchButton.Contains(Clicked)) {
                enterTitle = false;
                enterGenre = false;
                enterYear = true;
            }
            if (genreSearchButton.Contains(Clicked)) {
                enterTitle = false;
                enterGenre = true;
                enterYear = false;
            }

        }
        else{
            //display results
            window.draw(startOverSprite);
            window.draw(nextTenSprite);
            window.draw(prevTenSprite);

            text.setCharacterSize(35);
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Regular);
            text.setPosition(250, 50);
            text.setString("Search Results");
            window.draw(text);
            
            for (int i = 0; i < 10; i++) {
                if (i + offset == movies.size())
                    break;
                likeSprite.setPosition(sf::Vector2f(23, 100 + 20 * i));
                window.draw(likeSprite);
            }
            if (startOverButton.Contains(Clicked)) {
                state = 0;
                offset = 0;
            }
            DrawMovies(movies, offset, window);
            if (nextTenButton.Contains(Clicked) && (offset + 10) < movies.size()) 
                offset += 10;
            if (prevTenButton.Contains(Clicked) && (offset >= 10))
                offset -= 10;
            if (sf::FloatRect(23, 100, 26, 205).contains(Clicked.x, Clicked.y)) {
                bool found = false;
                Movie currMovie = movies[offset + (int)((float)(Clicked.y - 100) / (205.0f / 10.0f))];
                for (int i = 0; i < favoriteMovies.size(); i++) {
                    if (currMovie.getId() == favoriteMovies[i].getId()) {
                        favoriteMovies.erase(favoriteMovies.begin() + i);
                        found = true;
                    }
                }
                if (!found)
                    favoriteMovies.push_back(currMovie);
            }
        }
        
        window.display();
    }

    return 0;
}