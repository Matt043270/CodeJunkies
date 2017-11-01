#ifndef EXPLORESTATE_H
#define EXPLORESTATE_H

#include "GameState.h"
#include "InputManager.h"
#include "camera.h"
#include "DefineList.h"
#include "DisplayWorld.h"


class ExploreState : public GameState
{
public:

	ExploreState();

	void Initialize();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	virtual void MouseClick(int button, int state, int x, int y);
	virtual Camera GetCamera();

	void SetDimensions(int width, int height);
	void GetDimensions(int &width, int &height);
private:
	//--------------------------------------------------------------------------------------
	// Set up bounding boxes for collsion detection
	//--------------------------------------------------------------------------------------
	void CreateBoundingBoxes();

	void CreatePlains();

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

	// objects
	DisplayWorld m_displayWorld;

};

#endif