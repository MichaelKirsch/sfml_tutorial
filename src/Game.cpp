

#include "Game.h"

void Game::run(int framerate, int tickrate, int inputrate) {
    if(window.hasFocus())
    {
        auto time = clock.restart().asSeconds();
        elapsedFrame+=time;
        elapsedTick+=time;
        elapsedInput+=time;
        if(elapsedFrame>1.f/framerate)
        {
            elapsedFrame=0.f;
            this->render();
        }
        if(elapsedTick>1.f/tickrate)
        {
            elapsedTick=0.f;
            this->update();
        }
        if(elapsedInput>1.f/inputrate)
        {
            elapsedInput=0.f;
            this->input();
        }
    }
}

void Game::render() {
    this->window.clear({3, 252, 248});
    this->window.draw(ground);
    this->window.draw(player);
    this->window.display();
}

void Game::update() {
    velocity-=0.4;

    player.setPosition(player.getPosition().x,player.getPosition().y-velocity);
    if(player.getPosition().y+(player.getSize().y/2.f)>= ground.getPosition().y)
    {
        player.setPosition(player.getPosition().x,ground.getPosition().y-(player.getSize().y/2.f));
        velocity = 0.f;
    }
}

void Game::input() {
    sf::Event ev;
    while(window.pollEvent(ev))
    {

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)&&velocity<=0.01&&(player.getPosition().y+(player.getSize().y/2.f)>= ground.getPosition().y))
    {
        velocity+=10.f;
    }

}

Game::Game(sf::RenderWindow &rw) : window(rw){
    ground.setSize({static_cast<float>(window.getSize().x),window.getSize().y*0.1f});
    ground.setPosition(0.f,window.getSize().y*0.9f);
    ground.setFillColor({130, 61, 0});
    player.setSize({window.getSize().x*0.1f,window.getSize().y*0.1f});
    player.setOrigin(player.getSize().x/2.f,player.getSize().y/2.f);
    std::string path_to_texture;
    path_to_texture+=std::experimental::filesystem::current_path().parent_path().string();
    path_to_texture+="/data/tux.png";
    player_texture.loadFromFile(path_to_texture);
    player.setTexture(&player_texture);
    player.setPosition(window.getSize().x*0.2,window.getSize().y*0.5f);
}


