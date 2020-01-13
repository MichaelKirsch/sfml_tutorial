

#pragma once

#include "SFML/Graphics.hpp"

class Player : public sf::RectangleShape {
public:
    Player() = default;
    void create(sf::Vector2f groundpos,float velocity, float jumping_strength,float gravity, sf::Vector2f size, sf::Vector2f pos,sf::Texture* text);
    ~Player() = default;
    void update();
    bool jump();

private:
    float velocity,gravity;
    float jumping_strength;
    sf::Vector2f groundpos;
};



