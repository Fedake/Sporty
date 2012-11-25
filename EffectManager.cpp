#include "EffectManager.h"


EffectManager::EffectManager(void)
{
}

void EffectManager::update()
{
	float dt = m_dt.getElapsedTime().asMilliseconds();
	m_final = Effect();
	for(unsigned i = 0; i < m_effects.size(); i++)
	{
		m_final.jumpForce += m_effects[i].jumpForce;
		m_final.linearForce += m_effects[i].linearForce;

		m_final.lockJump |= m_effects[i].lockJump;
		m_final.lockMovement |= m_effects[i].lockMovement;


		m_effects[i].m_duration -= dt;
		if(m_effects[i].m_duration < 0)
		{
			eraseEffect(i);
			i--;
		}
	}

	m_dt.restart();
}

void EffectManager::eraseEffect(int i)
{
	m_final.jumpForce -= m_effects[i].jumpForce;
	m_final.linearForce -= m_effects[i].linearForce;

	m_final.lockJump = !m_effects[i].lockJump;
	m_final.lockMovement = !m_effects[i].lockMovement;
	m_effects.erase(m_effects.begin() + i);
}