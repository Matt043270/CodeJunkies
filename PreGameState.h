

#ifndef PREGAMESTATE_H
#define PREGAMESTATE_H

#include "GameState.h"
#include "InputManager.h"
#include "camera.h"
#include "AssetManager.h"
#include "DisplayWorld.h"

class PreGameState : public GameState
{
public:
	PreGameState();

	void Initialize();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	virtual Camera GetCamera();
	virtual void MouseClick(int button, int state, int x, int y);

	void SetDimensions(int width, int height);
	void GetDimensions(int &width, int &height);

private:
	Camera m_cam;
	// display campus map
	bool m_DisplayMap = false;
	// display welcome screen
	bool m_DisplayWelcome = true;
	// display exit screen
	bool m_DisplayExit = false;
	// display light fittings
	bool m_lightsOn;
	// display ECL block
	bool m_displayECL = true;

	// USE THESE STTEINGS TO CHANGE SPEED (on different spec computers)
	// Set speed (steps)
	GLdouble m_movementSpeed = 100.0;
	GLdouble m_rotationSpeed = 0.005;

	//--------------------------------------------------------------------------------------

	GLdouble m_stepIncrement;
	GLdouble m_angleIncrement;

	// varibles used for tarnslating graphics etc
	GLdouble m_step, m_step2, m_stepLength;

	int m_width, m_height;

	DisplayWorld m_displayWorld;

	AssetManager m_assetManager;

	// Temp Entity Housing
	EntityAIKart * m_KartOne, * m_KartTwo, * m_KartThree, * m_KartFour;

};

#endif