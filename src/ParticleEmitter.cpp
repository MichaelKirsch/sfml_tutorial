

#include "ParticleEmitter.h"

void ParticleEmitter::update() {
    auto elapsed = clock.restart().asSeconds();
    m_particleVertex.clear();
    std::vector<Particle> still_alife;
    for(auto particle:m_particles)
    {
        particle.update(elapsed);
        if(particle.isAlive())
        {
            still_alife.emplace_back(particle);
            auto vertices = particle.getVertices();
            for(auto vertex:vertices)
            {
                m_particleVertex.append(vertex);
            }
        }
    }
    m_particles = std::move(still_alife);
    while(m_particles.size()<m_amount_of_particles)
    {
        m_particles.emplace_back(Particle(m_pos,m_generalDirection,m_color,
                generateRandomFloatRange(m_min_velocity,m_max_velocity),m_size,
                generateRandomFloatRange(m_lifetime_min,m_lifetime_max),
                generateRandomFloatRange(m_min_abrasive,m_max_abrasive),
                generateRandomFloatRange(m_min_gravity,m_max_gravity)));
    }


}

float ParticleEmitter::generateRandomFloatRange(float min, float max) {
    return  min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));;
}

void ParticleEmitter::init(int particlesNumber,float size,sf::Color color, sf::Vector2f generalDirection, sf::Vector2f pos,
                           float max_velocity,float min_velocity, float max_abrasive,float min_abrasive, float max_gravity,float min_gravity, float lifetime_min,float lifetime_max) {
    this->m_pos = pos;
    this->m_size = size;
    this->m_generalDirection = generalDirection;
    this->m_amount_of_particles = particlesNumber;
    this->m_max_velocity = max_velocity;
    this->m_max_abrasive = max_abrasive;
    this->m_min_abrasive = min_abrasive;
    this->m_max_gravity = max_gravity;
    this->m_min_gravity = min_gravity;
    this->m_lifetime_max = lifetime_max;
    this->m_lifetime_min = lifetime_min;
    this->m_min_velocity = min_velocity;
    this->m_color = color;
    for(int x =0;x<m_amount_of_particles;x++)
    {
        m_particles.emplace_back(Particle(m_pos,m_generalDirection,m_color,
                generateRandomFloatRange(min_velocity,max_velocity),m_size,generateRandomFloatRange(lifetime_min,lifetime_max),
                generateRandomFloatRange(m_min_abrasive,m_max_abrasive),
                generateRandomFloatRange(m_min_gravity,m_max_gravity)));
    }
    m_particleVertex.setPrimitiveType(sf::Quads);
}


