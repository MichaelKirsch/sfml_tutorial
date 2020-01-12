

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
    this->window.draw(target);
    this->window.draw(text);
    this->window.display();
}

void Game::update() {
    if(game_running)
    {
        if(target.getPosition().x<0.f)
        {
            if(box_speed<10.f)
                box_speed+=0.5;
            counter++;
            target.setPosition(window.getSize().x,target.getPosition().y);
        } else
        {
            target.setPosition(target.getPosition().x-box_speed,target.getPosition().y);
        }
        velocity-=0.4;
        player.setPosition(player.getPosition().x,player.getPosition().y-velocity);
        if(player.getPosition().y+(player.getSize().y/2.f)>= ground.getPosition().y)
        {
            player.setPosition(player.getPosition().x,ground.getPosition().y-(player.getSize().y/2.f));
            velocity = 0.f;
        }

        auto tux_left = player.getPosition().x -(player.getSize().x/2.f);
        auto tux_right = tux_left+player.getSize().x;
        auto tux_top = player.getPosition().y -(player.getSize().y/2.f);
        auto tux_bottom = tux_top + player.getSize().y;

        auto target_left = target.getPosition().x;
        auto target_right = target_left+target.getSize().x;
        auto target_top = target.getPosition().y;
        auto target_bottom = target_top + target.getSize().y;

        if(target_left<tux_right && tux_bottom > target_top && target_right>tux_left)
        {
            game_running = false;
        }
        text.setString("Counter: "+std::to_string(counter));
    } else
    {
        text.setString("Game Over at "+std::to_string(counter));
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
    std::string path_to_data;
    path_to_data+=std::experimental::filesystem::current_path().parent_path().string();
    path_to_data+="/data/";
    player_texture.loadFromFile(path_to_data+"tux.png");
    target_texture.loadFromFile(path_to_data+"build.png");
    font.loadFromFile(path_to_data+"UbuntuMono-R.ttf");
    text.setFont(font);
    text.setCharacterSize(window.getSize().y*0.07f);
    text.setPosition(window.getSize().x*0.02,window.getSize().y*0.02);
    text.setFillColor({119, 3, 252});
    player.setTexture(&player_texture);
    player.setPosition(window.getSize().x*0.2,window.getSize().y*0.5f);

    target.setSize({window.getSize().x*0.1f,window.getSize().x*0.1f});
    target.setPosition(window.getSize().x,ground.getPosition().y-target.getSize().y);
    target.setTexture(&target_texture);
}


