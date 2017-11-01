#ifndef GAMERUNNINGSTATE_H
#define GAMERUNNINGSTATE_H

#include "GameState.h"

class GameRunningState : public GameState
{
public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
	virtual void MouseClick(int button, int state, int x, int y);
	virtual Camera GetCamera();
private:

private:
	Camera m_camera;
};

#endif