#include "Effect.h"


Effect::Effect(int type, int category, int effect, int target, Player* playerL, Player* playerR)
				: m_type(type), m_category(category), m_effect(effect), m_target(target), m_playerL(playerL), m_playerR(playerR)
{
	m_time.restart();

	std::cout << "type:" << m_type << " cat:" << m_category << std::endl;

	if (m_type == T_DEBUFF)
		switch (m_category)
		{
			case C_SPEED:
				getPlayer(m_target)->setSpeed(2);
				break;
			case C_JUMP:
				getPlayer(m_target)->setJump(3);
				break;
			default:
				break;
		}
	
	if (m_type == T_NEUTRAL)
		switch (m_category)
		{
			case C_SPEED:
				getPlayer(m_target)->setSpeed(4);
				break;
			case C_JUMP:
				getPlayer(m_target)->setJump(4);
				break;
			default:
				break;
		}

	if (m_type == T_BUFF)
		switch (m_category)
		{
			case C_SPEED:
				getPlayer(m_target)->setSpeed(6);
				break;
			case C_JUMP:
				getPlayer(m_target)->setJump(5);
				break;
			default:
				break;
		}
}

Effect::~Effect()
{
	switch (m_category)
	{
		case C_SPEED:
			getPlayer(m_target)->setSpeed(4);
			break;
		case C_JUMP:
			getPlayer(m_target)->setJump(4);
			break;
		default:
			break;
	}
}