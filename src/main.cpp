#include <iostream>
#include "SFML/Graphics.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800,600),"Hello",sf::Style::Default);

    while(window.isOpen())
    {
        sf::Event ev;
        while(window.pollEvent(ev))
        {
            
        }

    }

}
