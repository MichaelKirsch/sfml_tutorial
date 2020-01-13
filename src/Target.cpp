

#include "Target.h"

bool Target::reset() {
    if(window!= nullptr)
    {
        if(this->getPosition().x<0.f)
        {
            this->setPosition(window->getSize().x,this->getPosition().y);
            if(speed<max_speed)
                speed+=accel;
            return true;
        }

    }
    return false;
}

void Target::update() {
    if(!reset())
        this->setPosition(this->getPosition().x-speed,this->getPosition().y);
    else
        score = true;
}

bool Target::getScore() {
    bool buf = score;
    score = false;
    return buf;
}

void Target::setInit(sf::RenderWindow *window, float speed, float max_speed, float accel, sf::Vector2f size,
                     sf::Vector2f pos, sf::Texture* text) {
    this->setTexture(text);
    this->setSize(size);
    this->setPosition(pos.x,pos.y-this->getSize().y);
    this->window = window;
    this->speed = speed;
    this->max_speed = max_speed;
    this->accel = accel;
}
