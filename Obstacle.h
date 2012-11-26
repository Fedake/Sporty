#pragma once
#include "Entity.h"

class Obstacle : public Entity
{
public:
	Obstacle(b2World* world, sf::RenderWindow* win, b2Vec2 pos, float radius);
	Obstacle(b2World* world, sf::RenderWindow* win, b2Vec2 pos, b2Vec2 size, float angle);

	void render();

private:
	b2PolygonShape m_box;
	b2CircleShape m_circle;

	sf::RectangleShape m_boxShape;
	sf::CircleShape m_circleShape;

	int m_type;
};

