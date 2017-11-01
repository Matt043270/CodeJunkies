#include "PreGameState.h"

PreGameState::PreGameState()
{

}

void PreGameState::Initialize()
{
	m_cam.Position(50000, 8200, 34000, 90.0);
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
	EntityKart * KartOne = new EntityKart();
	KartOne->SetId(3);
	KartOne->AddModel(objKart, 0, 0, 0);
	//ntyKart->Translate(50000, 7700, 35000);
	KartOne->Translate(49750, 7700, 35000);
	KartOne->Rotate(0, 0, 0);
	KartOne->Scale(50, 50, 50);
	KartOne->Initialize();
	m_assetManager.AddEntity(KartOne);


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
	/*Texture * texFuel = new Texture();
	LoadTexture("data/models/fuel.raw", texFuel, 512, 512);
	AddTexture(texFuel);

	StaticModel * objFuel = new StaticModel();
	LoadObjFile("data/models/fuel.obj", objFuel);
	objFuel->LoadToCalllist(505);
	objFuel->SetTexture(texFuel);
	AddModel(objFuel);

	EntityFuel * ntyFuel = new EntityFuel();
	ntyFuel->SetId(10);
	ntyFuel->AddModel(objFuel, 0, 0, 0);
	ntyFuel->Translate(50000, 7700, 35000);
	ntyFuel->Rotate(0, 0, 0);
	ntyFuel->Scale(500, 500, 500);
	AddEntity(ntyFuel);*/

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
	//assetManager.LoadAllAssets();
	//assetManager.LoadGameStateAssets();
}

void PreGameState::draw(const float dt)
{
	m_assetManager.RenderLoadedEntities(true);
}

void PreGameState::update(const float dt)
{
	m_KartTwo->Tick();
	m_KartThree->Tick();
	m_KartFour->Tick();

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