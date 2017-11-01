#include "pregamestate.h"


PreGameState::PreGameState()
{

}

void PreGameState::draw(const float dt)
{
	// displays the welcome screen
	if (m_DisplayWelcome) m_cam.DisplayWelcomeScreen(m_width, m_height, 1, m_displayWorld.getWelcomeTex());
	// displays the exit screen
	if (m_DisplayExit) m_cam.DisplayWelcomeScreen(m_width, m_height, 0, m_displayWorld.getExitTex());
	// displays the map
	if (m_DisplayMap) m_cam.DisplayMap(m_width, m_height, m_displayWorld.getMapTex());

	assetManager.LoadAllAssets();
}

void PreGameState::update(const float dt)
{
	m_stepIncrement = dt * 1400;
	m_angleIncrement = 0.07f;//dx;

	handleInput();

	// check for movement
	m_cam.CheckCamera();

	m_cam.SetMoveSpeed(m_movementSpeed);
	m_cam.SetRotateSpeed(m_angleIncrement);

}

void PreGameState::handleInput()
{
	// Direction keys down
	if (InputManager::GetInstance()->GetKeyState(227) == IM_KEY_PRESSED)
	{
		m_cam.DirectionRotateLR(-1);
	}
	if (InputManager::GetInstance()->GetKeyState(229) == IM_KEY_PRESSED)
	{
		m_cam.DirectionRotateLR(1);
	}
	if (InputManager::GetInstance()->GetKeyState(228) == IM_KEY_PRESSED)
	{
		m_cam.DirectionFB(1);
	}
	if (InputManager::GetInstance()->GetKeyState(230) == IM_KEY_PRESSED)
	{
		m_cam.DirectionFB(-1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'Z') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'z') == IM_KEY_PRESSED)
	{
		m_cam.DirectionLR(-1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'X') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'x') == IM_KEY_PRESSED)
	{
		m_cam.DirectionLR(1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'Q') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'q') == IM_KEY_PRESSED)
	{
		m_cam.DirectionLookUD(1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'A') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'a') == IM_KEY_PRESSED)
	{
		m_cam.DirectionLookUD(-1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'M') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'m') == IM_KEY_PRESSED)
	{
		m_DisplayMap = !m_DisplayMap;
	}
	if (InputManager::GetInstance()->GetKeyState(27) == IM_KEY_PRESSED)
	{
		m_cam.SetRotateSpeed(0.0f);
		m_cam.SetMoveSpeed(0.0f);
		m_DisplayExit = true;
	}
	if (InputManager::GetInstance()->GetKeyState((int)' ') == IM_KEY_PRESSED)
	{
		m_DisplayWelcome = !m_DisplayWelcome;
	}
	if (InputManager::GetInstance()->GetKeyState((int)'L') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'l') == IM_KEY_PRESSED)
	{
		m_lightsOn = !m_lightsOn;
	}
	if (InputManager::GetInstance()->GetKeyState((int)'P') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'p') == IM_KEY_PRESSED)
	{
		m_displayECL = !m_displayECL;
	}

	// keys up
	if (InputManager::GetInstance()->GetKeyState(227) == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState(229) == IM_KEY_RELEASED)
	{
		m_cam.DirectionRotateLR(0);
	}
	if (InputManager::GetInstance()->GetKeyState(228) == IM_KEY_RELEASED && InputManager::GetInstance()->GetInstance()->GetKeyState(230) == IM_KEY_RELEASED)
	{
		m_cam.DirectionFB(0);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'X') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'x') == IM_KEY_RELEASED &&
		InputManager::GetInstance()->GetKeyState((int)'Z') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'z') == IM_KEY_RELEASED)
	{
		m_cam.DirectionLR(0);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'A') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'a') == IM_KEY_RELEASED &&
		InputManager::GetInstance()->GetKeyState((int)'Q') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'q') == IM_KEY_RELEASED)
	{
		m_cam.DirectionLookUD(0);
	}
}


Camera PreGameState::GetCamera()
{
	return m_cam;
}

void PreGameState::MouseClick(int button, int state, int x, int y)
{
	// exit tour if clicked on exit splash screen
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if ((m_DisplayExit) && (x <= m_width / 2.0 + 256.0) && (x >= m_width / 2.0 - 256.0)
			&& (y <= m_height / 2.0 + 256.0) && (y >= m_height / 2.0 - 256.0))
		{
			m_displayWorld.deleteImageFromMemory();
			exit(1);
		}
	}
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