#include "GameRunningState.h"

GameRunningState::GameRunningState()
{

}

void GameRunningState::Initialize()
{
	m_cam.Position(49500, 8400, 34000, 0.0);
	m_cam.SetLookY(-0.4f);
	
	
	// Track
	Texture * texTrack = new Texture();
	//LoadTexture("data/models/imagemapTrack.raw", texTrack, 1024, 512);
	AssetManager::LoadTexture("data/models/trackBake.raw", texTrack, 1024, 1024);
	m_assetManager.AddTexture(texTrack);

	StaticModel * objTrack = new StaticModel();
	AssetManager::LoadObjFile("data/models/track.obj", objTrack);
	objTrack->LoadToCalllist(501);
	objTrack->SetTexture(texTrack);
	m_assetManager.AddModel(objTrack);

	Entity * ntyTrack = new Entity();
	ntyTrack->SetId(2);
	ntyTrack->AddModel(objTrack, 0, 0, 0);
	ntyTrack->Translate(62136, 7600, 46000);
	ntyTrack->Rotate(0, 90, 0);
	ntyTrack->Scale(130, 130, 130);
	m_assetManager.AddEntity(ntyTrack);

	// Kart
	Texture * texKart = new Texture();
	AssetManager::LoadTexture("data/models/kartRedBaked.raw", texKart, 2048, 2048);
	//LoadTexture("data/models/Trex.raw", texKart, 512, 512);
	m_assetManager.AddTexture(texKart);

	StaticModel * objKart = new StaticModel();
	AssetManager::LoadObjFile("data/models/kartRedBaked.obj", objKart);
	//LoadObjFile("data/models/trex.obj", objKart);
	objKart->LoadToCalllist(502);
	objKart->SetTexture(texKart);
	m_assetManager.AddModel(objTrack);

	/*EntityKart * ntyKart = new EntityKart();
	ntyKart->SetId(3);
	ntyKart->AddModel(objKart, 0, 0, 0);
	ntyKart->Translate(50000, 7700, 35000);
	//ntyKart->Translate(34000, 10450, 42000);
	ntyKart->Rotate(0, 0, 0);
	ntyKart->Scale(50, 50, 50);
	ntyKart->Initialize();
	AddEntity(ntyKart);*/


	//KartOne - Player
	m_KartOne = new EntityKart();
	m_KartOne->SetId(3);
	m_KartOne->AddModel(objKart, 0, -10, -20);
	//ntyKart->Translate(50000, 7700, 35000);
	m_KartOne->Translate(49750, 7700, 35000);
	m_KartOne->Rotate(0, 0, 0);
	m_KartOne->Scale(50, 50, 50);
	m_KartOne->Initialize();
	m_assetManager.AddEntity(m_KartOne);


	// KartTwo - AI
	m_KartTwo = new EntityAIKart("data/paths/smartPath.txt");
	m_KartTwo->SetId(4);
	m_KartTwo->AddModel(objKart, 0, 0, 0);
	m_KartTwo->Translate(50250, 7700, 35000);
	m_KartTwo->Rotate(0, 0, 0);
	m_KartTwo->Scale(50, 50, 50);
	m_KartTwo->Initialize();
	m_assetManager.AddEntity(m_KartTwo);


	// KartThree - AI
	m_KartThree = new EntityAIKart("data/paths/drunkPath.txt");
	m_KartThree->SetId(5);
	m_KartThree->AddModel(objKart, 0, 0, 0);
	m_KartThree->Translate(49750, 7700, 35500);
	m_KartThree->Rotate(0, 0, 0);
	m_KartThree->Scale(50, 50, 50);
	m_KartThree->Initialize();
	m_assetManager.AddEntity(m_KartThree);


	// KartFour - AI
	m_KartFour = new EntityAIKart("data/paths/crashPath.txt");
	m_KartFour->SetId(6);
	m_KartFour->AddModel(objKart, 0, 0, 0);
	m_KartFour->Translate(50250, 7700, 35500);
	m_KartFour->Rotate(0, 0, 0);
	m_KartFour->Scale(50, 50, 50);
	m_KartFour->Initialize();
	m_assetManager.AddEntity(m_KartFour);


	// Fuel
	Texture * texFuel = new Texture();
	AssetManager::LoadTexture("data/models/fuelBake.raw", texFuel, 512, 512);
	m_assetManager.AddTexture(texFuel);

	StaticModel * objFuel = new StaticModel();
	AssetManager::LoadObjFile("data/models/fuel.obj", objFuel);
	objFuel->LoadToCalllist(505);
	objFuel->SetTexture(texFuel);
	m_assetManager.AddModel(objFuel);

	EntityFuel * ntyFuel = new EntityFuel();
	ntyFuel->SetId(10);
	ntyFuel->AddModel(objFuel, 0, 0, 0);
	ntyFuel->Translate(50000, 7700, 35000);
	ntyFuel->Rotate(0, 0, 0);
	ntyFuel->Scale(500, 500, 500);
	m_assetManager.AddEntity(ntyFuel);

	// Bleachers
	Texture * texBleachers = new Texture();
	AssetManager::LoadTexture("data/models/bleacherBake.raw", texBleachers, 1024, 1024);
	m_assetManager.AddTexture(texBleachers);

	StaticModel * objBleachers = new StaticModel();
	AssetManager::LoadObjFile("data/models/bleacherBaked.obj", objBleachers);
	objBleachers->LoadToCalllist(503);
	objBleachers->SetTexture(texBleachers);
	m_assetManager.AddModel(objBleachers);

	Entity * ntyBleachers1 = new Entity();
	ntyBleachers1->SetId(7);
	ntyBleachers1->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers1->Translate(45000, 7900, 26000);
	ntyBleachers1->Rotate(0, -20, 0);
	ntyBleachers1->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers1);

	Entity * ntyBleachers2 = new Entity();
	ntyBleachers2->SetId(8);
	ntyBleachers2->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers2->Translate(53000, 7900, 21000);
	ntyBleachers2->Rotate(0, -90, 0);
	ntyBleachers2->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers2);

	Entity * ntyBleachers3 = new Entity();
	ntyBleachers3->SetId(9);
	ntyBleachers3->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers3->Translate(58000, 7900, 21000);
	ntyBleachers3->Rotate(0, -90, 0);
	ntyBleachers3->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers3);

	Entity * ntyBleachers4 = new Entity();
	ntyBleachers4->SetId(10);
	ntyBleachers4->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers4->Translate(63000, 7900, 21000);
	ntyBleachers4->Rotate(0, -90, 0);
	ntyBleachers4->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers4);

	Entity * ntyBleachers5 = new Entity();
	ntyBleachers5->SetId(11);
	ntyBleachers5->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers5->Translate(70000, 7900, 26000);
	ntyBleachers5->Rotate(0, -160, 0);
	ntyBleachers5->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers5);

	Entity * ntyBleachers6 = new Entity();
	ntyBleachers6->SetId(12);
	ntyBleachers6->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers6->Translate(45000, 7900, 76000);
	ntyBleachers6->Rotate(0, 20, 0);
	ntyBleachers6->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers6);

	Entity * ntyBleachers7 = new Entity();
	ntyBleachers7->SetId(13);
	ntyBleachers7->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers7->Translate(53000, 7900, 81000);
	ntyBleachers7->Rotate(0, 90, 0);
	ntyBleachers7->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers7);

	Entity * ntyBleachers8 = new Entity();
	ntyBleachers8->SetId(14);
	ntyBleachers8->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers8->Translate(58000, 7900, 81000);
	ntyBleachers8->Rotate(0, 90, 0);
	ntyBleachers8->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers8);

	Entity * ntyBleachers9 = new Entity();
	ntyBleachers9->SetId(15);
	ntyBleachers9->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers9->Translate(63000, 7900, 81000);
	ntyBleachers9->Rotate(0, 90, 0);
	ntyBleachers9->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers9);

	Entity * ntyBleachers10 = new Entity();
	ntyBleachers10->SetId(16);
	ntyBleachers10->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers10->Translate(70000, 7900, 76000);
	ntyBleachers10->Rotate(0, 160, 0);
	ntyBleachers10->Scale(300, 300, 300);
	m_assetManager.AddEntity(ntyBleachers10);

	// Grass
	Texture * texGrass = new Texture();
	AssetManager::LoadTexture("data/grassPlane.raw", texGrass, 512, 512);
	m_assetManager.AddTexture(texGrass);
	m_assetManager.GenerateTrackPlane(499, texGrass);

	// Finish Line
	Texture * texFinishLine = new Texture();
	AssetManager::LoadTexture("data/models/finishLineBake.raw", texFinishLine, 1024, 1024);
	m_assetManager.AddTexture(texFinishLine);

	StaticModel * objFinishLine = new StaticModel();
	AssetManager::LoadObjFile("data/models/finishLineBake.obj", objFinishLine);
	objFinishLine->LoadToCalllist(504);
	objFinishLine->SetTexture(texFinishLine);
	m_assetManager.AddModel(objFinishLine);

	Entity * ntyFinishLine = new Entity();
	ntyFinishLine->SetId(17);
	ntyFinishLine->AddModel(objFinishLine, 0, 0, 0);
	ntyFinishLine->Translate(50500, 7700, 34000);
	ntyFinishLine->Rotate(0, 90, 0);
	ntyFinishLine->Scale(300, 300, 500);
	m_assetManager.AddEntity(ntyFinishLine);

	// Speedo
	m_texSpeedo = new Texture();
	AssetManager::LoadTexture("data/speedo.raw", m_texSpeedo, 128, 128);

	m_texGameOver = new Texture();
	AssetManager::LoadTexture("data/gameOver.raw", m_texGameOver, 1024, 1024);
}

void GameRunningState::draw(const float dt)
{
	m_assetManager.RenderLoadedEntities(true);
	//m_fuelLoader.RenderFuel();
	if (m_gameOver)
	{
		UI::Draw2DImage(0, 0, m_width, m_height, 0, m_texGameOver);
	}
	//UI::Draw2DImage(128, 128, 128, 128, 90, m_texSpeedo);
}

void GameRunningState::update(const float dx)
{
	m_KartTwo->Tick();
	m_KartThree->Tick();
	m_KartFour->Tick();

	m_stepIncrement = dx * 1400;
	m_angleIncrement = dx * 0.5f;
	m_movementSpeed = dx * 1500;

	handleInput();

	// check for movement
	m_cam.CheckCamera();

	m_cam.SetMoveSpeed(m_movementSpeed);
	m_cam.SetRotateSpeed(m_angleIncrement);

	m_KartOne->SetPosition(m_cam.GetLR(), m_cam.GetUD(), m_cam.GetFB());
	float angle = 180 / PI;
	angle *= m_cam.GetRotationLR();
	m_KartOne->SetRotation(0, -angle, 0);

	if (m_cam.GetLR() >= 49435 && m_cam.GetLR() <= 51382 &&
		m_cam.GetFB() >= 37449 && m_cam.GetFB() <= 37724)
	{
		m_gameOver = true;
		m_cam.DirectionFB(0);
		m_cam.DirectionLR(0);
	}
}

void GameRunningState::handleInput()
{
	if (!m_gameOver)
	{
		if (InputManager::GetInstance()->GetKeyState((int)'w') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'W') == IM_KEY_PRESSED)
		{
			m_KartOne->Accelerate();
			m_cam.DirectionFB(1);

		}
		if (InputManager::GetInstance()->GetKeyState((int)'s') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'S') == IM_KEY_PRESSED)
		{
			m_KartOne->Brake();
			m_cam.DirectionFB(-1);
		}
		if (InputManager::GetInstance()->GetKeyState((int)'a') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'A') == IM_KEY_PRESSED)
		{
			m_KartOne->Turn(LEFT);
			m_cam.DirectionRotateLR(-1);
		}
		if (InputManager::GetInstance()->GetKeyState((int)'d') == IM_KEY_PRESSED || InputManager::GetInstance()->GetKeyState((int)'D') == IM_KEY_PRESSED)
		{
			m_KartOne->Turn(RIGHT);
			m_cam.DirectionRotateLR(1);
		}
	}
	if (InputManager::GetInstance()->GetKeyState((int)'s') == IM_KEY_RELEASED && InputManager::GetInstance()->GetInstance()->GetKeyState((int)'S') == IM_KEY_RELEASED && 
		InputManager::GetInstance()->GetKeyState((int)'w') == IM_KEY_RELEASED && InputManager::GetInstance()->GetInstance()->GetKeyState((int)'W') == IM_KEY_RELEASED)
	{
		m_cam.DirectionFB(0);
	}
	if (InputManager::GetInstance()->GetKeyState((int)'a') == IM_KEY_RELEASED && InputManager::GetInstance()->GetInstance()->GetKeyState((int)'A') == IM_KEY_RELEASED &&
		InputManager::GetInstance()->GetKeyState((int)'d') == IM_KEY_RELEASED && InputManager::GetInstance()->GetInstance()->GetKeyState((int)'D') == IM_KEY_RELEASED)
	{
		m_cam.DirectionRotateLR(0);
	}
}


Camera GameRunningState::GetCamera()
{
	return m_cam;
}

void GameRunningState::MouseClick(int button, int state, int x, int y)
{

}

void GameRunningState::SetDimensions(int width, int height)
{
	m_width = width;
	m_height = height;
}

void GameRunningState::GetDimensions(int &width, int &height)
{
	width = m_width;
	height = m_height;
}