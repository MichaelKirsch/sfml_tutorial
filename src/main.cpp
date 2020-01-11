#include <iostream>
#include "SFML/Graphics.hpp"


int main() {

    const sf::Vector2i resolution = {800,600};
    sf::RenderWindow window(sf::VideoMode(resolution.x,resolution.y),"Hello",sf::Style::Default);
    sf::Clock clock;

    auto elapsed = 0.f;
    const int framerate = 50;

    sf::RectangleShape rect;

    rect.setSize({resolution.x*0.1f,resolution.y*0.1f});
    rect.setOrigin(rect.getSize().x/2.f,rect.getSize().y/2.f);
    rect.setFillColor({100,0,0});
    rect.setPosition(resolution.x/2.f,resolution.y/2.f);
    while(window.isOpen())
    {
        auto time = clock.restart().asSeconds();

        sf::Event ev;
        while (window.pollEvent(ev)){}

        elapsed+=time;
        if(elapsed> 1.f/framerate)
        {
            window.clear();
            window.draw(rect);
         //render
            window.display();
        }

    }

}
