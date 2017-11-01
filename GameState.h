#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameManager.h"
#include "camera.h"

class GameState
{
public:
	GameManager* gameManager;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
	virtual void MouseClick(int button, int state, int x, int y) = 0;
	virtual Camera GetCamera() = 0;

};

#endif