#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

class Effect
{
	private:
		b2World* m_world;
		sf::RenderWindow* m_win;

		int m_type;
		int m_effect;
		int m_target;
		int m_duration;
	public:
		Effect(b2World* world, sf::RenderWindow* win, int type, int target);
};

