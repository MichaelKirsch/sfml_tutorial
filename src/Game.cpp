

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
    this->window.draw(p_emitter.getVAO());
    this->window.draw(mouse_emit.getVAO());
    this->window.draw(text);
    this->window.display();
}

void Game::update() {

    if(game_running)
    {
        p_emitter.update();
        mouse_emit.update();
        player.update();
        target.update();
        p_emitter.setPos({target.getPosition().x+target.getSize().x,target.getPosition().y+target.getSize().y/2.f});
        mouse_emit.setPos({player.getPosition().x+player.getSize().x/2.f,player.getPosition().y});
        mouse_emit.setColor(sf::Color{static_cast<sf::Uint8>(rand()%255),static_cast<sf::Uint8>(rand()%255),static_cast<sf::Uint8>(rand()%255)});
        if(hitdetection(player,target))
            game_running= false;
        else
            if(target.getScore())
                counter++;
        text.setString("Counter: "+std::to_string(counter));
    } else
    {
        if(counter > highscore)
            highscore=counter;
        text.setString("Game Over at "+std::to_string(counter) + ", Highscore is:"+std::to_string(highscore));
    }
}

void Game::input() {
    sf::Event ev;
    while(window.pollEvent(ev))
    {

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        if(game_running)
            player.jump();
        if(!game_running)
        {
            game_running = true;
            counter = 0;
            target.setPosition(window.getSize().x,target.getPosition().y);

        }
    }
}

Game::Game(sf::RenderWindow &rw) : window(rw){
    ground.setSize({static_cast<float>(window.getSize().x),window.getSize().y*0.1f});
    ground.setPosition(0.f,window.getSize().y*0.9f);
    ground.setFillColor({130, 61, 0});
    std::string path_to_data;
    path_to_data+=std::experimental::filesystem::current_path().parent_path().string();
    path_to_data+="/data/";
    font.loadFromFile(path_to_data+"UbuntuMono-R.ttf");
    text.setFont(font);
    text.setCharacterSize(window.getSize().y*0.07f);
    text.setPosition(window.getSize().x*0.02,window.getSize().y*0.02);
    text.setFillColor({119, 3, 252});
    player_texture.loadFromFile(path_to_data+"tux.png");
    target_texture.loadFromFile(path_to_data+"monster-truck.png");
    target.setInit(&window,8.f,15.f,0.4f,{window.getSize().x*0.1f,window.getSize().x*0.1f},
            {static_cast<float>(window.getSize().x),ground.getPosition().y},&target_texture);
    player.create(ground.getPosition(),0.f,13.f,0.5,{window.getSize().x*0.1f,window.getSize().y*0.1f},
            {window.getSize().x*0.2f,window.getSize().y*0.5f},&player_texture);
    p_emitter.init(500,10.f,{
            237, 76, 76
    },{1,1},target.getPosition(),10.f,5.f,0.3,-0.3,0.3,-0.3,0.5f,1.5f);
    mouse_emit.init(50,8.f,{92, 92, 92},{1,1},{player.getPosition().x+player.getSize().x/2.f,player.getPosition().y},10.f,5.f,0.5,-0.5,1.0,0.99,0.5f,1.5f);
}

bool Game::hitdetection(sf::RectangleShape &rec1, sf::RectangleShape &rec2) {
    auto glob1 = rec1.getGlobalBounds();
    auto glob2 = rec2.getGlobalBounds();
    return (glob1.intersects(glob2));
}


