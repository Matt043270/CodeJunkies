#include "ExploreState.h"

ExploreState::ExploreState()
{

}

void ExploreState::Initialize()
{
	Texture * texHallway = new Texture();
	AssetManager::LoadTexture("data/models/imagemapHallway.raw", texHallway, 2048, 1024);
	m_assetManager.AddTexture(texHallway);

	StaticModel * objHallway = new StaticModel();
	AssetManager::LoadObjFile("data/models/hallway.obj", objHallway);
	objHallway->LoadToCalllist(500);
	objHallway->SetTexture(texHallway);
	m_assetManager.AddModel(objHallway);

	Entity * ntyHallway = new Entity();
	ntyHallway->SetId(1);
	ntyHallway->AddModel(objHallway, 0, 0, 0);
	ntyHallway->SetPosition(34350, 10000, 42097);
	ntyHallway->SetRotation(0, 180, 0);
	ntyHallway->Scale(13.5f, 8.8f, 9.9f);
	m_assetManager.AddEntity(ntyHallway);
	// set the world co-ordinates (used to set quadrants for bounding boxes)
	m_cam.SetWorldCoordinates(36000.0, 43200.0);
	// turn collision detection on
	m_cam.SetCollisionDetectionOn(true);
	// set number of bounding boxes required
	m_cam.SetNoBoundingBoxes(19);
	// set starting position of user
	//m_cam.Position(32720.0, 9536.0,	4800.0, 180.0);
	// Start at hallway
	m_cam.Position(34000, 10450.0, 42000.0, 90.0);
	//cam.Position(50000, 8200, 34000, 90.0);

	CreateBoundingBoxes();
	CreatePlains();

	// copies bounding boxes from array to linked lists (one fopr each quadrant)
	m_cam.InitiateBoundingBoxes();

	// load texture images and create display lists
	m_displayWorld.DrawWorld();

	m_texGameBoard = new Texture();
	AssetManager::LoadTexture("data/ntkgBoard.raw", m_texGameBoard, 1024, 512);

}

void ExploreState::update(const float dx)
{
	m_stepIncrement = dx * 1400;
	m_angleIncrement = dx * 1.6f;
	m_movementSpeed = dx * 3500;
	handleInput();

	// check for movement
	m_cam.CheckCamera();
	if (m_cam.GetLR() >= 44970 && m_cam.GetLR() <= 46000 &&
		m_cam.GetFB() >= 41322 && m_cam.GetFB() <= 42779 &&
		m_cam.GetUD() == 9685)
	{
		m_displayGameStartScreen = true;
	}
	else
	{
		m_displayGameStartScreen = false;
	}
	m_cam.SetMoveSpeed(m_movementSpeed);
	m_cam.SetRotateSpeed(m_angleIncrement);


}

void ExploreState::draw(const float dx)
{
	// displays the welcome screen
	if (m_DisplayWelcome) m_cam.DisplayWelcomeScreen(m_width, m_height, 1, m_displayWorld.getWelcomeTex());
	// displays the exit screen
	if (m_DisplayExit) m_cam.DisplayWelcomeScreen(m_width, m_height, 0, m_displayWorld.getExitTex());
	// displays the map
	if (m_DisplayMap) m_cam.DisplayMap(m_width, m_height, m_displayWorld.getMapTex());
	// display images
	m_displayWorld.RenderWorld(m_lightsOn);
	m_assetManager.RenderLoadedEntities(false);
	if (m_displayGameStartScreen) m_cam.DisplayWelcomeScreen(m_width, m_height, 1, m_texGameBoard->GetTextureId());

}

void ExploreState::handleInput()
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
	if (InputManager::GetInstance()->GetKeyState((int)'H') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'h') == IM_KEY_PRESSED)
	{
		m_cam.DirectionUD(1);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'B') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'b') == IM_KEY_PRESSED)
	{
		m_cam.DirectionUD(-1);
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
	if (InputManager::GetInstance()->GetKeyState(13) == IM_KEY_PRESSED)
	{
		if (m_displayGameStartScreen)
		{
			m_preGameState->Initialize();
			m_gameManager->changeState(m_preGameState);
		}
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
	if (InputManager::GetInstance()->GetKeyState((int)'H') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'h') == IM_KEY_RELEASED &&
		InputManager::GetInstance()->GetKeyState((int)'B') == IM_KEY_RELEASED && InputManager::GetInstance()->GetKeyState((int)'b') == IM_KEY_RELEASED)
	{
		m_cam.DirectionUD(0);
	}
}

Camera ExploreState::GetCamera()
{
	return m_cam;
}

void ExploreState::CreateBoundingBoxes()
{

	// chanc block
	m_cam.SetAABBMaxX(0, 35879.0);
	m_cam.SetAABBMinX(0, 33808.0);
	m_cam.SetAABBMaxZ(0, 22096.0);
	m_cam.SetAABBMinZ(0, 4688.0);

	// between chanc block and phys sci
	m_cam.SetAABBMaxX(1, 35999.0);
	m_cam.SetAABBMinX(1, 35730.0);
	m_cam.SetAABBMaxZ(1, 25344.0);
	m_cam.SetAABBMinZ(1, 22096.0);

	// phy sci block panel 1
	m_cam.SetAABBMaxX(2, 35879.0);
	m_cam.SetAABBMinX(2, 33808.0);
	m_cam.SetAABBMaxZ(2, 26752.0);
	m_cam.SetAABBMinZ(2, 25344.0);

	// phy sci block 1st doorway
	m_cam.SetAABBMaxX(3, 35879.0);
	m_cam.SetAABBMinX(3, 34256.0);
	m_cam.SetAABBMaxZ(3, 27559.0);
	m_cam.SetAABBMinZ(3, 26752.0);

	// phy sci block 2nd panel
	m_cam.SetAABBMaxX(4, 35879.0);
	m_cam.SetAABBMinX(4, 33808.0);
	m_cam.SetAABBMaxZ(4, 36319.0);
	m_cam.SetAABBMinZ(4, 27559.0);

	// phy sci block 2nd doorway
	m_cam.SetAABBMaxX(5, 35879.0);
	m_cam.SetAABBMinX(5, 34260.0);
	m_cam.SetAABBMaxZ(5, 37855.0);
	m_cam.SetAABBMinZ(5, 36319.0);

	// phy sci block 3rd panel
	m_cam.SetAABBMaxX(6, 35879.0);
	m_cam.SetAABBMinX(6, 33808.0);
	m_cam.SetAABBMaxZ(6, 41127.0);
	m_cam.SetAABBMinZ(6, 37855.0);

	// drinks machine
	m_cam.SetAABBMaxX(7, 35879.0);
	m_cam.SetAABBMinX(7, 34704.0);
	m_cam.SetAABBMaxZ(7, 25344.0);
	m_cam.SetAABBMinZ(7, 24996.0);

	// bottom of steps
	m_cam.SetAABBMaxX(8, 33808.0);
	m_cam.SetAABBMinX(8, 0.0);
	m_cam.SetAABBMaxZ(8, 4688.0);
	m_cam.SetAABBMinZ(8, 0.0);

	// library end panel
	m_cam.SetAABBMaxX(10, 50000.0);
	m_cam.SetAABBMinX(10, 6514.0);
	m_cam.SetAABBMaxZ(10, 50000.0);
	m_cam.SetAABBMinZ(10, 43036.0);

	// KBLT
	m_cam.SetAABBMaxX(11, 28104.0);
	m_cam.SetAABBMinX(11, 25608.0);
	m_cam.SetAABBMaxZ(11, 43046.0);
	m_cam.SetAABBMinZ(11, 42754.0);

	// Canteen block
	m_cam.SetAABBMaxX(12, 2608.0);
	m_cam.SetAABBMinX(12, 0.0);
	m_cam.SetAABBMaxZ(12, 49046.0);
	m_cam.SetAABBMinZ(12, 0.0);

	// Telephones
	m_cam.SetAABBMaxX(13, 33892.0);
	m_cam.SetAABBMinX(13, 33872.0);
	m_cam.SetAABBMaxZ(13, 25344.0);
	m_cam.SetAABBMinZ(13, 25173.0);

	// Telephones
	m_cam.SetAABBMaxX(14, 34277.0);
	m_cam.SetAABBMinX(14, 34157.0);
	m_cam.SetAABBMaxZ(14, 25344.0);
	m_cam.SetAABBMinZ(14, 25173.0);

	// Telephones
	m_cam.SetAABBMaxX(15, 35462.0);
	m_cam.SetAABBMinX(15, 34541.0);
	m_cam.SetAABBMaxZ(15, 25344.0);
	m_cam.SetAABBMinZ(15, 25173.0);

	// Wall by Steps
	m_cam.SetAABBMaxX(16, 31548.0);
	m_cam.SetAABBMinX(16, 31444.0);
	m_cam.SetAABBMaxZ(16, 10395.0);
	m_cam.SetAABBMinZ(16, 4590.0);

	// Team CodeJunkies inner hallway wall
	m_cam.SetAABBMaxX(17, 50000.0);
	m_cam.SetAABBMinX(17, 34320.0);
	m_cam.SetAABBMaxZ(17, 41127.0);
	m_cam.SetAABBMinZ(17, 41000.0);

	// Team CodeJunkies game portal
	m_cam.SetAABBMaxX(18, 46000.0);
	m_cam.SetAABBMinX(18, 45500.0);
	m_cam.SetAABBMaxZ(18, 42779.0);
	m_cam.SetAABBMinZ(18, 41322.0);
}

//--------------------------------------------------------------------------------------
// Set up co-ordinates of different plains
//--------------------------------------------------------------------------------------

void ExploreState::CreatePlains()
{
	// grass slope
	m_cam.SetPlains(ZY_PLAIN, 4848.0, 31568.0, 9536.0, 10450.0, 6200.0, 10000.0);

	// flat land (pavement and grass)
	m_cam.SetPlains(FLAT_PLAIN, 0.0, 34320.0, 10450.0, 10450.0, 10000.0, 17000.0);
	m_cam.SetPlains(FLAT_PLAIN, 0.0, 6500.0, 10450.0, 10450.0, 17000.0, 40000.0);
	m_cam.SetPlains(FLAT_PLAIN, 27000.0, 34320.0, 10450.0, 10450.0, 17000.0, 40000.0);
	m_cam.SetPlains(FLAT_PLAIN, 0.0, 34320.0, 10450.0, 10450.0, 40000.0, 50000.0);


	// top of lower hill
	m_cam.SetPlains(FLAT_PLAIN, 9000.0, 22000.0, 10650.0, 10650.0, 19000.0, 23000.0);
	m_cam.SetPlains(FLAT_PLAIN, 9000.0, 10000.0, 10650.0, 10650.0, 28000.0, 33000.0);
	m_cam.SetPlains(FLAT_PLAIN, 9000.0, 22000.0, 10650.0, 10650.0, 36000.0, 37000.0);
	// sides of lower hill
	m_cam.SetPlains(ZY_PLAIN, 6500.0, 27000.0, 10450.0, 10650.0, 17000.0, 19000.0);
	m_cam.SetPlains(ZY_PLAIN, 6500.0, 27000.0, 10650.0, 10450.0, 37000.0, 40000.0);
	m_cam.SetPlains(XY_PLAIN, 6500.0, 9000.0, 10450.0, 10650.0, 17000.0, 40000.0);
	m_cam.SetPlains(XY_PLAIN, 22000.0, 27000.0, 10650.0, 10450.0, 17000.0, 40000.0);

	// top of higher hill
	m_cam.SetPlains(FLAT_PLAIN, 14000.0, 18000.0, 10875.0, 108075.0, 28000.0, 33000.0);
	// sides of higher hill
	m_cam.SetPlains(ZY_PLAIN, 10000.0, 22000.0, 10650.0, 10875.0, 23000.0, 28000.0);
	m_cam.SetPlains(ZY_PLAIN, 10000.0, 22000.0, 10875.0, 10650.0, 33000.0, 36000.0);
	m_cam.SetPlains(XY_PLAIN, 10000.0, 14000.0, 10650.0, 10875.0, 23000.0, 36000.0);
	m_cam.SetPlains(XY_PLAIN, 18000.0, 22000.0, 10875.0, 10650.0, 23000.0, 36000.0);

	//entance steps
	m_step = 10450.0;
	m_stepLength = 9808.0;
	for (int i = 0; i < 18; i++)
	{
		m_cam.SetPlains(FLAT_PLAIN, 31582.0, 33835, m_step, m_step, m_stepLength, m_stepLength + 42.0);
		m_step -= 48.0;
		m_stepLength -= 142.0;
		if ((i + 3) % 5 == 0)
		{
			m_stepLength -= 500.0;
			m_step -= 48.0;
		}
	}

	// temp plain to take down to ECL1
	m_cam.SetPlains(ZY_PLAIN, 3200.0, 4800.0, 10450.0, 9370.0, 53400.0, 57900.0);


	// Team CodeJunkies hallway
	GLdouble teamStep = 10450.0;
	GLdouble teamStepLength = 34320.0;
	for (int i = 0; i < 18; i++)
	{
		m_cam.SetPlains(FLAT_PLAIN, teamStepLength, teamStepLength + 128.0, teamStep, teamStep, 41127.0, 43056.0);
		teamStep -= 45.0;
		teamStepLength += 128.0;
		if (i == 8)
		{
			teamStep -= 0.0;
			teamStepLength += 7640.0;
		}
	}
}

void ExploreState::SetDimensions(int width, int height)
{
	m_width = width;
	m_height = height;
}

void ExploreState::GetDimensions(int &width, int &height)
{
	width = m_width;
	height = m_height;
}

void ExploreState::MouseClick(int button, int state, int x, int y)
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

void ExploreState::AddPreGameState(PreGameState * state)
{
	m_preGameState = state;
}