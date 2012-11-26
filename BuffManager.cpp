#include "BuffManager.h"
#include <iostream>

BuffManager::BuffManager(b2World* world, sf::RenderWindow* win, Player* playerL, Player* playerR) 
							: 	m_world(world), m_win(win), m_playerL(playerL), m_playerR(playerR)
{
	m_buffs.clear();
	m_time.restart();

	for (int j = 0; j < 2; ++j)
	for (int i = 0; i < EFFECT_COUNT; ++i)
	{
		m_effects[j][i] = NULL;
	}
}

void BuffManager::addBuff(Buff* buff)
{
	m_buffs.push_back(buff);
}

void BuffManager::update()
{
	if ((m_time.getElapsedTime().asSeconds() > 3) && (m_buffs.size() < 3))
	{
		BuffEffect eff;
		eff.type = rand() % 3;
		eff.category = rand() % 2;
		eff.effect = 0;
		Buff* buff = new Buff(m_world, m_win, eff);
		addBuff(buff);

		m_time.restart();
	}
	for(unsigned i = 0; i < m_buffs.size(); i++)
	{
		if(m_buffs[i]->isPicked())
		{
			delete m_buffs[i];
			m_buffs.erase(m_buffs.begin() + i);
			i--;
		}
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

void BuffManager::setEffect(Buff* buff, int target)
{
	if (target == -1)
		if (m_effects[0][0] != NULL)
		{
			delete m_effects[0][0];
			m_effects[0][1] = NULL;
		}
	if (target == 1)
		if (m_effects[1][0] != NULL)
		{
			delete m_effects[1][0];
			m_effects[0][1] = NULL;
		}

	m_effects[target == -1 ? 0 : 1][0] = new Effect(buff->getBuffEffect().type, buff->getBuffEffect().category, 
														buff->getBuffEffect().effect, target, m_playerL, m_playerR);

	buff->pick();
}