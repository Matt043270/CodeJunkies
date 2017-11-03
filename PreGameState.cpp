#include "PreGameState.h"

PreGameState::PreGameState()
{

}

void PreGameState::Initialize()
{
	m_cam.Position(48000, 8200, 34000, 90.0);
	m_texGameSplash = new Texture();

	AssetManager::LoadTexture("data/PreGameSplash.raw", m_texGameSplash, 1024, 1024);
	
}

void PreGameState::draw(const float dt)
{
	UI::Draw2DImage(0, 0, m_width, m_height, 0, m_texGameSplash);
}

void PreGameState::update(const float dt)
{
	handleInput();

	// check for movement
	m_cam.CheckCamera();
}

void PreGameState::handleInput()
{
	if (InputManager::GetInstance()->GetKeyState(13) == IM_KEY_PRESSED)
	{
		m_gameRunningState->Initialize();
		m_gameManager->changeState(m_gameRunningState);
	}
}


Camera PreGameState::GetCamera()
{
	return m_cam;
}

void PreGameState::MouseClick(int button, int state, int x, int y)
{
	
}

void PreGameState::SetDimensions(int width, int height)
{
	m_width = width;
	m_height = height;
}

void PreGameState::GetDimensions(int &width, int &height)
{
	width = m_width;
	height = m_height;
}

void PreGameState::AddGameRunningState(GameRunningState * state)
{
	m_gameRunningState = state;
}