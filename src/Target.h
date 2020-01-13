

#pragma once

#include "SFML/Graphics.hpp"

class Target : public sf::RectangleShape {
public:
    Target() = default;
    void setInit(sf::RenderWindow* window, float speed,float max_speed, float accel, sf::Vector2f size, sf::Vector2f pos,sf::Texture* text);
    ~Target() = default;
    void update();
    bool getScore();
private:
    sf::RenderWindow* window;
    bool reset();
    float speed,accel,max_speed;
    bool score = false;
protected:
};



