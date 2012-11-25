#pragma once
#include "Buff.h"

class EffectManager
{
public:
	EffectManager();

	Effect m_final;

	void update();
	void eraseEffect(int i);
	void addEffect(Effect effect){m_effects.push_back(effect);}

private:
	sf::Clock m_dt;
	std::vector<Effect> m_effects;

};

