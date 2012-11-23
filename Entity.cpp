#include "Entity.h"

Entity::Entity(b2World* world, sf::RenderWindow* win, int type) : m_world(world), m_win(win), m_type(type)
{
}

void Entity::render()
{
	m_win->draw(m_sprite); 
	m_win->draw(m_shape); 
}