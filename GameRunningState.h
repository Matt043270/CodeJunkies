#ifndef GAMERUNNINGSTATE_H
#define GAMERUNNINGSTATE_H

#include "GameState.h"
#include "InputManager.h"
#include "camera.h"
#include "AssetManager.h"
#include "DisplayWorld.h"
#include "UI.h"
#include "FuelLoader.h"

class GameRunningState : public GameState
{
public:
	GameRunningState();

		/**
		* Initializes the game state
		*/
	void Initialize();

		/**
		* Draws the game state.
		* @param[in] dt The delta time.
		*/
	virtual void draw(const float dt);
		/**
		* Updates the game state.
		* @param[in] dt The delta time.
		*/
	virtual void update(const float dt);
		/**
		* Handles the input of the state
		*/
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
	EntityKart * m_KartOne;
	EntityAIKart * m_KartTwo, *m_KartThree, *m_KartFour;

	Texture * m_texSpeedo;
	Texture * m_texGameOver;
	//FuelLoader m_fuelLoader;

	bool m_gameOver = false;
};
#endif