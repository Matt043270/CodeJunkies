#include "gameManager.h"
#include "gameState.h"
#include <stack>

void GameManager::pushState(GameState* state)
{
	this->states.push(state);

	return;
}
//
//void GameManager::popState()
//{
//	delete this->states.top();
//	this->pushState.pop();
//
//	return;
//}
//
//void GameManager::changeState(GameState* state)
//{
//	if (!this->states.empty())
//	{
//		popState();
//	}
//	pushState(state);
//
//	return;
//}

GameState* GameManager::peekState()
{
	if (this->states.empty())
	{
		return nullptr;
	}

	return this->states.top();
}

void GameManager::gameLoop()
{

}

GameManager::GameManager()
{

}

//GameManager::~GameManager()
//{
//	while (!this->states.empty())
//	{
//		popState();
//	}
//}