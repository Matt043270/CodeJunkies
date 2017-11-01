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
		/**
		 * Default constructor
		 */
	EntityKart();
		/**
		 * Default destructor
		 */
	~EntityKart();

		/**
		 * Initialize the kart entity, setting all the members to the defaults.
		 */
	void Initialize();
		/**
		 * Any final clean up should be done here.
		 */
	void Unload();

		/**
		 * Causes the kart to accelerate by the acceleration, up to a max set by MAX_SPEED
		 */
	void Accelerate();
		/**
		 * Causes the kart to slow down using BRAKE_DECAY, down to a min set by MIN_SPEED.
		 * If MIN_SPEED is less than 0, allow reversing.
		 */
	void Brake();
		/**
		 * The kart will perform the needed decays when not doing anything. The speed and turn angle will decay back to 0.
		 */
	void Idle();
		/**
		 * Turns the kart by the direction. The speed is defined by TURN_SPEED, and the most it can turn is defined by MAX_TURN_SPEED
		 * @param[in] dir The direction that the kart is turning.
		 */
	void Turn(KartTurnDirection dir);

		/**
		 * Called every frame. The tick method will perform the needed translations to the entity itself.
		 */
	void Tick();
private:

protected:
		/**
		 * The current speed of the kart
		 */
	float m_speed;
		/**
		 * The turning speed of the kart.
		 */
	float m_turnSpeed;

		/**
		 * The current direction that the kart is turning.
		 */
	KartTurnDirection m_direction;
		/**
		 * Constant value that defined the max speed of the kart.
		 */
	const float MAX_SPEED = 20;
		/**
		 * Constant value that determines the min speed of the kart.
		 * Negative values will allow reversing.
		 */
	const float MIN_SPEED = -5; // Reversing
		/**
		 * Constant value that determines the max turning speed of the kart.
		 */
	const float MAX_TURN_SPEED = 10;
		/**
		 * Constant value that determines the amount that the turning speed will decay by.
		 */
	const float TURN_DECAY = 5;
		/**
		 * Constant value that determines how fast the kart will turn.
		 */
	const float TURN_SPEED = 5;
		/**
		 * Constant value that determines how fast the kart will accelerate.
		 */
	const float ACCELERATION = 3;
		/**
		 * Constant value that determines how fast the kart will slow down when braking.
		 */
	const float BRAKE_DECAY = 3;
		/**
		 * Constant value that determines how fast the kart will lose speed while idling.
		 */
	const float SPEED_DECAY = 1;
};

#endif