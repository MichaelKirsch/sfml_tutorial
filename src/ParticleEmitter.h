

#pragma once

#include <list>
#include <stack>
#include "SFML/Graphics.hpp"
#include "Particle.h"
class ParticleEmitter {
public:
    ParticleEmitter()= default;
    void init(int particlesNumber,float size,sf::Color color, sf::Vector2f generalDirection, sf::Vector2f pos,
            float max_velocity,float min_velocity, float max_abrasive,float min_abrasive, float max_gravity,float min_gravity, float lifetime_min,float lifetime_max);

    sf::VertexArray& getVAO(){ return m_particleVertex;};
    ~ParticleEmitter() = default;
    void update();
    void setColor(sf::Color color){m_color = color;};
    void setPos(sf::Vector2f pos){m_pos = pos;};
private:
    sf::Clock clock;
    int m_amount_of_particles;
    std::vector<Particle> m_particles;
    sf::VertexArray m_particleVertex;
    float m_max_velocity,m_min_velocity,m_lifetime_min,m_lifetime_max,m_min_abrasive,m_max_abrasive,m_min_gravity,m_max_gravity,m_size;
    float generateRandomFloatRange(float min, float max);
    sf::Vector2f m_generalDirection,m_pos;
    sf::Color m_color;
};



