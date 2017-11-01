#pragma once
#include <stack>

class GameState;

class GameManager
{
public:
	std::stack<GameState*> states;

	void pushState(GameState* state);
	//void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	GameManager();
	//~GameManager();
};