

#include "Player.h"

void Player::create(sf::Vector2f groundpos,float velocity, float jumping_strength,float gravity,
        sf::Vector2f size, sf::Vector2f pos,sf::Texture* text){
    this->setPosition(pos);
    this->setTexture(text);
    this->setSize(size);
    this->groundpos = groundpos;
    this->velocity = velocity;
    this->jumping_strength = jumping_strength;
    this->gravity = gravity;
}

void Player::update() {
    velocity-=gravity;
    this->setPosition(this->getPosition().x,this->getPosition().y-velocity);
    if(this->getPosition().y+this->getSize().y>groundpos.y)
    {
        this->setPosition(this->getPosition().x,groundpos.y-this->getSize().y);
        velocity = 0.f;
    }
}

bool Player::jump() {
    if(velocity<=0.01&&this->getPosition().y+this->getSize().y>=groundpos.y)
    {
        velocity+=jumping_strength;
        return true;
    }
    return false;
}


