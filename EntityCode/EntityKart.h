#ifndef ENTITYKART_H
#define ENTITYKART_H
#include "Entity.h"

enum KartTurnDirection
{
	NONE = 0,
	LEFT = -1,
	RIGHT = 1
};

class EntityKart : public Entity
{
public:
	EntityKart();
	~EntityKart();

	void Initialize();
	void Unload();

	void Accelerate();
	void Brake();
	void Idle();
	void Turn(KartTurnDirection dir);

	void Tick();
private:

private:
	float m_speed;
	float m_turnAngle;
	KartTurnDirection m_direction;
	const float MAX_SPEED = 20;
	const float MIN_SPEED = -5; // Reversing
	const float MAX_TURN_SPEED = 10;
	const float TURN_DECAY = 5;
	const float TURN_SPEED = 5;
	const float ACCELERATION = 3;
	const float BRAKE_DECAY = 3;
	const float SPEED_DECAY = 1;
};

#endif