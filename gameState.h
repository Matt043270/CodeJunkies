#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameManager.h"

class GameState
{
public:
	GameManager* gameManager;

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
};

#endif