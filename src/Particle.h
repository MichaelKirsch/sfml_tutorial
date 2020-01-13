

#pragma once

#include "SFML/Graphics.hpp"
#include "math.h"

class Particle {
public:
    Particle(sf::Vector2f pos,sf::Vector2f direction,sf::Color color,float inertia,float size, float lifetime, float abrasive, float gravity);
    void update(float elapsed);
    bool isAlive(){ return m_age<m_max_age;};
    std::array<sf::Vertex,4>& getVertices(){return m_vertices;};
    ~Particle() = default;
private:
    void refactor();
    std::array<sf::Vertex,4> m_vertices;
    sf::Color m_color;
    sf::Vector2f m_pos,m_direction;
    float m_size,m_age,m_max_age,m_gravity,m_abrasive,m_speed;
    sf::Uint8 m_transparency;
};



