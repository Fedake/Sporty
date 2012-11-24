#pragma once
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

#include "Level.h"

#define MTP 40

class Engine
{
	private:
		sf::RenderWindow* m_win;

		Level* m_level;
	public:
		Engine(int w, int h, int bpp = 32);

		void run();

		void input();
		void update(sf::Time dt);
		void render();
};