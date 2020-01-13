

#include "Particle.h"

Particle::Particle(sf::Vector2f pos, sf::Vector2f direction, sf::Color color, float inertia, float size, float lifetime,
                   float abrasive, float gravity) {
    m_transparency = 255;
    this->m_age = 0.f;
    this->m_size= size;
    this->m_color = color;
    this->m_max_age = lifetime;
    this->m_speed = inertia;
    this->m_pos = pos;
    this->m_gravity = gravity;
    this->m_abrasive = abrasive;
    this->m_direction = direction;
    refactor();
}

void Particle::refactor() {
    auto half_size = m_size/2.f;
    m_vertices[0].position = {m_pos.x-half_size,m_pos.y-half_size};
    m_vertices[0].color = {m_color.r, m_color.g, m_color.b,m_transparency};
    m_vertices[1].position = {m_pos.x+half_size,m_pos.y-half_size};
    m_vertices[1].color = {m_color.r, m_color.g, m_color.b,m_transparency};
    m_vertices[2].position = {m_pos.x+half_size,m_pos.y+half_size};
    m_vertices[2].color = {m_color.r, m_color.g, m_color.b,m_transparency};
    m_vertices[3].position = {m_pos.x-half_size,m_pos.y+half_size};
    m_vertices[3].color = {m_color.r, m_color.g, m_color.b,m_transparency};
}

void Particle::update(float elapsed) {
    m_age+=elapsed;
    float percent_brightnes = ((1.f/m_max_age)*m_age);
    m_transparency = 255.f- 255*percent_brightnes;
    m_direction.x -=m_abrasive;
    m_direction.y -=m_gravity;
    m_pos+=m_direction;
    refactor();
}
