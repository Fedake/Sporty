#include "BuffManager.h"


BuffManager::BuffManager(b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win), m_interval(0)
{
	m_dt.restart();
}

void BuffManager::reset()
{
	while(m_buffs.size() != 0)
	{
		delete m_buffs[0].m_buff;
		m_buffs.erase(m_buffs.begin());
	}

	m_interval = 0;
}

void BuffManager::update()
{
	float dt = m_dt.getElapsedTime().asMilliseconds();
	m_interval += dt;

	for(unsigned i = 0; i < m_buffs.size(); i++)
	{
		m_buffs[i].m_timeLeft -= dt;

		if(m_buffs[i].m_timeLeft < 0)
		{
			delete m_buffs[i].m_buff;
			m_buffs.erase(m_buffs.begin() + i);
			i--;
		}
	}

	if(m_interval >= 5000)
	{
		//if(rand()%4 == 3)
		{
			BuffInfo buff;
			buff.m_buff = new Buff(m_world, m_win);
			buff.m_timeLeft = ((rand()%30) + 30)*1000;
			m_buffs.push_back(buff);
		}

		m_interval = 0;
	}


	m_dt.restart();
}

void BuffManager::enableBuff(int index)
{
}

void BuffManager::render()
{
	for(unsigned i = 0; i < m_buffs.size(); i++)
	{
		m_buffs[i].m_buff->render();
	}
}