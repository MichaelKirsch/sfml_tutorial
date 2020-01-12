#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"

int main() {

    const sf::Vector2i resolution = {800,600};
    sf::RenderWindow window(sf::VideoMode(resolution.x,resolution.y),"Hello",sf::Style::Default);
    Game game(window);
    while(window.isOpen())
    {
        game.run(60,30,120);
    }
}
