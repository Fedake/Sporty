#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "Buff.h"

struct BuffInfo
{
	Buff* m_buff;
	int m_timeLeft;
};

class BuffManager
{
public:
	BuffManager(b2World* world, sf::RenderWindow* win);

	void reset();
	void update();

	void render();

private:
	b2World* m_world;
	sf::RenderWindow* m_win;


	sf::Clock m_dt;

	float m_interval;

	std::vector<BuffInfo> m_buffs;

};

