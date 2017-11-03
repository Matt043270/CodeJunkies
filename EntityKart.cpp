#include "EntityKart.h"

EntityKart::EntityKart()
{

}

EntityKart::~EntityKart()
{

}

void EntityKart::Initialize()
{
	m_speed = 100;
	m_direction = NONE;
	m_turnSpeed = 0;
}

void EntityKart::Unload()
{

}

void EntityKart::Accelerate()
{
	m_speed += ACCELERATION;
	if (m_speed > MAX_SPEED)
	{
		m_speed = MAX_SPEED;
	}
}

void EntityKart::Idle()
{
	if (m_speed > 0)
	{
		m_speed -= SPEED_DECAY;
		if (m_speed < 0)
		{
			m_speed = 0;
		}
	}
	else if (m_speed < 0)
	{
		m_speed += SPEED_DECAY;
		if (m_speed > 0)
		{
			m_speed = 0;
		}
	}
	if (m_turnSpeed > 0)
	{
		m_turnSpeed -= TURN_DECAY;
		if (m_turnSpeed <= 0)
		{
			m_turnSpeed = 0;
			m_direction = NONE;
		}
	}
}

void EntityKart::Brake()
{
	m_speed -= BRAKE_DECAY;
	if (m_speed < MIN_SPEED)
	{
		m_speed = MIN_SPEED;
	}
}

void EntityKart::Turn(KartTurnDirection dir)
{
	int turnDelta = (m_direction == dir) ? 1 : -1;
	m_turnSpeed += turnDelta * TURN_SPEED;
	if (m_turnSpeed > MAX_TURN_SPEED)
	{
		m_turnSpeed = MAX_TURN_SPEED;
	}
	else if(m_turnSpeed < 0)
	{
		m_direction = dir;
		m_turnSpeed *= -1;
	}
}

void EntityKart::Tick()
{

}