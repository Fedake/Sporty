#include "BuffManager.h"
#include <iostream>

BuffManager::BuffManager(b2World* world, sf::RenderWindow* win) : m_world(world), m_win(win)
{
	m_buffs.clear();
	m_time.restart();
}

void BuffManager::addBuff(Buff* buff)
{
	m_buffs.push_back(buff);
}

void BuffManager::update()
{
	if ((m_time.getElapsedTime().asSeconds() > 20) && (m_buffs.size() < 3))
	{
		int type = rand() % 3;
		Buff* buff = new Buff(m_world, m_win, type);
		addBuff(buff);

		m_time.restart();
	}
}

void BuffManager::render()
{
	for (unsigned i = 0; i < m_buffs.size(); ++i)
	{
		m_buffs[i]->render();
	}
}

void BuffManager::reset()
{
	for (unsigned i = 0; i < m_buffs.size(); ++i)
	{
		delete m_buffs[i];
	}
	m_buffs.clear();
	m_time.restart();
}