

#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include <experimental/filesystem>

class Game {
public:
    Game(sf::RenderWindow& rw);
    void run(int framerate, int tickrate, int inputrate);
    ~Game() = default;

private:
    void render();
    void update();
    void input();
    float velocity = 0.f;
    sf::Vector2f getPlayerFootPosition();

    sf::Clock clock;
    float elapsedFrame,elapsedTick,elapsedInput;
    sf::RenderWindow& window;
    sf::RectangleShape ground;
    sf::RectangleShape player;
    sf::Texture player_texture;
    sf::RectangleShape target;
};



