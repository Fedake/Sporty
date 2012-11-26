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
		if(m_buffs[i]->getTimeLeft() <= 0 || m_buffs[i]->isPicked())
		{
			delete m_buffs[i];
			m_buffs.erase(m_buffs.begin() + i);
			i--;
		}
	}

	for (unsigned i = 0; i < 2; ++i)
	for (unsigned j = 0; j < 1; ++j)
	{
		if (m_effects[i][j] != NULL)
		if (m_effects[i][j]->getTimeLeft() <= 0)
		{
			delete m_effects[i][j];
			m_effects[i][j] = NULL;
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
		if (m_effects[0][buff->getBuffEffect().category] != NULL)
		{
			delete m_effects[0][buff->getBuffEffect().category];
			m_effects[0][buff->getBuffEffect().category] = NULL;
		}
	if (target == 1)
		if (m_effects[1][buff->getBuffEffect().category] != NULL)
		{
			delete m_effects[1][buff->getBuffEffect().category];
			m_effects[1][buff->getBuffEffect().category] = NULL;
		}

	m_effects[target == -1 ? 0 : 1][buff->getBuffEffect().category] = new Effect(buff->getBuffEffect().type, buff->getBuffEffect().category, 
														buff->getBuffEffect().effect, target, m_playerL, m_playerR);

	buff->pick();
}