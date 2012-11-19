#pragma once
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class Engine
{
	private:
		sf::RenderWindow* m_win;
		b2World* m_world;
		b2Vec2 m_gravity;
		float32 timeStep;


		b2Body* m_box;
		sf::RectangleShape m_shape;

		sf::Vector2i m_mPos;
		sf::Vector2f m_mGPos;

		sf::Text m_info;

	public:
		Engine(int w, int h, int bpp = 32);

		void run();

		void input();
		void update(sf::Time dt);
		void render();
};