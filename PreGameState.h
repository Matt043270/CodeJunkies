#ifndef PREGAMESTATE_H
#define PREGAMESTATE_H

#include "GameState.h"
#include "InputManager.h"
#include "camera.h"
#include "AssetManager.h"
#include "DisplayWorld.h"
#include "UI.h"
#include "GameRunningState.h"

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

	void AddGameRunningState(GameRunningState * state);

private:
	Camera m_cam;
	
	int m_width, m_height;

	Texture * m_texGameSplash;

	GameRunningState * m_gameRunningState;
};

#endif