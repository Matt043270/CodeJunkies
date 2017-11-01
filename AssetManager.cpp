#include "AssetManager.h"

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{

}

void AssetManager::LoadObjFile(std::string objFile, StaticModel * model)
{
	using namespace std;
	ifstream file(objFile);
	string line = "";
	const string v = "v ";
	const string f = "f ";
	const string vt = "vt ";
	if (!file.is_open())
	{
		cout << "Failed to open object: " << objFile << endl;
		return;
	}
	stringstream ss;
	string lineItem = "";
	while (getline(file, line))
	{
		ss.str(line);

		// Vertex
		if (line.compare(0, v.length(), v) == 0)
		{
			string pre, x, y, z;
			ss >> pre >> x >> y >> z;
			Vertex v;
			v.x = strtof(x.c_str(), NULL);
			v.y = strtof(y.c_str(), NULL);
			v.z = strtof(z.c_str(), NULL);

			model->AddVertex(v);
		}

		// Texture
		if (line.compare(0, vt.length(), vt) == 0)
		{
			string pre, u, v;
			ss >> pre >> u >> v;
			TexCoord tex;

			tex.u = strtof(u.c_str(), NULL);
			tex.v = 1 - (strtof(v.c_str(), NULL));
			model->AddTextureCoord(tex);
		}

		// Face
		if (line.compare(0, v.length(), f) == 0)
		{
			string pre, f1, f2, f3;
			string fv1, fv2, fv3, ft1, ft2, ft3, fn1, fn2, fn3;
			Face f;
			ss >> pre >> f1 >> f2 >> f3;
			// Face 1
			ss.clear();
			ss.str(f1);
			getline(ss, fv1, '/');
			getline(ss, ft1, '/');
			getline(ss, fn1);
			// Face 2
			ss.clear();
			ss.str(f2);
			getline(ss, fv2, '/');
			getline(ss, ft2, '/');
			getline(ss, fn2);
			// Face 3
			ss.clear();
			ss.str(f3);
			getline(ss, fv3, '/');
			getline(ss, ft3, '/');
			getline(ss, fn3);

			f.v1 = stoi(fv1.c_str(), NULL);
			f.v2 = stoi(fv2.c_str(), NULL);
			f.v3 = stoi(fv3.c_str(), NULL);
			f.t1 = stoi(ft1.c_str(), NULL);
			f.t2 = stoi(ft2.c_str(), NULL);
			f.t3 = stoi(ft3.c_str(), NULL);
			f.n1 = stoi(fn1.c_str(), NULL);
			f.n2 = stoi(fn2.c_str(), NULL);
			f.n3 = stoi(fn3.c_str(), NULL);

			model->AddFace(f);

		}
		ss.clear();
	}
	file.close();
}

void AssetManager::LoadTexture(std::string texFile, Texture * tex, int width, int height, bool clamp)
{
	using namespace std;

	FILE * f;
	int size = width * height * 3;
	unsigned char * image = (unsigned char*)malloc(sizeof(unsigned char) * size);
	f = fopen(texFile.c_str(), "rb");
	if (f == NULL)
	{
		cout << "AssetManager::LoadTexture -> " << texFile << " not found." << endl;
		exit(0);
	}
	fread(image, size, 1, f);
	fclose(f);

	GLuint texId;
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	if (clamp)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	}
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);
	tex->SetTextureId(texId);
}

void AssetManager::LoadAllAssets()
{
	// Hallway
	Texture * texHallway = new Texture();
	LoadTexture("data/models/hallwayBake.raw", texHallway, 2048, 2048);
	AddTexture(texHallway);

	StaticModel * objHallway = new StaticModel();
	LoadObjFile("data/models/hallway.obj", objHallway);
	objHallway->LoadToCalllist(500);
	objHallway->SetTexture(texHallway);
	AddModel(objHallway);

	Entity * ntyHallway = new Entity();
	ntyHallway->SetId(1);
	ntyHallway->AddModel(objHallway, 0, 0, 0);
	ntyHallway->SetPosition(34350, 10000, 42097);
	ntyHallway->SetRotation(0, 180, 0);
	ntyHallway->Scale(13.5f, 8.8f, 9.9f);
	AddEntity(ntyHallway);

	// Track
	Texture * texTrack = new Texture();
	//LoadTexture("data/models/imagemapTrack.raw", texTrack, 1024, 512);
	LoadTexture("data/models/trackBake.raw", texTrack, 1024, 1024);
	AddTexture(texTrack);

	StaticModel * objTrack = new StaticModel();
	LoadObjFile("data/models/track.obj", objTrack);
	objTrack->LoadToCalllist(501);
	objTrack->SetTexture(texTrack);
	AddModel(objTrack);

	Entity * ntyTrack = new Entity();
	ntyTrack->SetId(2);
	ntyTrack->AddModel(objTrack, 0, 0, 0);
	ntyTrack->Translate(62136, 7600, 46000);
	ntyTrack->Rotate(0, 90, 0);
	ntyTrack->Scale(130, 130, 130);
	AddEntity(ntyTrack);

	// Kart
	Texture * texKart = new Texture();
	LoadTexture("data/models/kartRedBaked.raw", texKart, 2048, 2048);
	//LoadTexture("data/models/Trex.raw", texKart, 512, 512);
	AddTexture(texKart);

	StaticModel * objKart = new StaticModel();
	LoadObjFile("data/models/kartRedBaked.obj", objKart);
	//LoadObjFile("data/models/trex.obj", objKart);
	objKart->LoadToCalllist(502);
	objKart->SetTexture(texKart);
	AddModel(objTrack);


	//KartOne
	EntityKart * KartOne = new EntityKart();
	KartOne->SetId(3);
	KartOne->AddModel(objKart, 0, 0, 0);
	//ntyKart->Translate(50000, 7700, 35000);
	KartOne->Translate(49750, 7700, 35000);
	KartOne->Rotate(0, 0, 0);
	KartOne->Scale(50, 50, 50);
	KartOne->Initialize();
	AddEntity(KartOne);


	// KartTwo
	EntityKart * KartTwo = new EntityKart();
	KartTwo->SetId(4);
	KartTwo->AddModel(objKart, 0, 0, 0);
	KartTwo->Translate(50250, 7700, 35000);
	KartTwo->Rotate(0, 0, 0);
	KartTwo->Scale(50, 50, 50);
	KartTwo->Initialize();
	AddEntity(KartTwo);


	// KartThree
	EntityKart * KartThree = new EntityKart();
	KartThree->SetId(4);
	KartThree->AddModel(objKart, 0, 0, 0);
	KartThree->Translate(49750, 7700, 35500);
	KartThree->Rotate(0, 0, 0);
	KartThree->Scale(50, 50, 50);
	KartThree->Initialize();
	AddEntity(KartThree);


	// KartFour
	EntityKart * KartFour = new EntityKart();
	KartFour->SetId(4);
	KartFour->AddModel(objKart, 0, 0, 0);
	KartFour->Translate(50250, 7700, 35500);
	KartFour->Rotate(0, 0, 0);
	KartFour->Scale(50, 50, 50);
	KartFour->Initialize();
	AddEntity(KartFour);




	// Bleachers
	Texture * texBleachers = new Texture();
	LoadTexture("data/models/BleacherBake.raw", texBleachers, 1024, 1024);
	AddTexture(texBleachers);

	StaticModel * objBleachers = new StaticModel();
	LoadObjFile("data/models/bleacherBaked.obj", objBleachers);
	objBleachers->LoadToCalllist(503);
	objBleachers->SetTexture(texBleachers);
	AddModel(objBleachers);

	Entity * ntyBleachers1 = new Entity();
	ntyBleachers1->SetId(4);
	ntyBleachers1->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers1->Translate(45000, 7900, 26000);
	ntyBleachers1->Rotate(0, -20, 0);
	ntyBleachers1->Scale(300, 300, 300);
	AddEntity(ntyBleachers1);

	Entity * ntyBleachers2 = new Entity();
	ntyBleachers2->SetId(5);
	ntyBleachers2->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers2->Translate(53000, 7900, 21000);
	ntyBleachers2->Rotate(0, -90, 0);
	ntyBleachers2->Scale(300, 300, 300);
	AddEntity(ntyBleachers2);

	Entity * ntyBleachers3 = new Entity();
	ntyBleachers3->SetId(6);
	ntyBleachers3->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers3->Translate(58000, 7900, 21000);
	ntyBleachers3->Rotate(0, -90, 0);
	ntyBleachers3->Scale(300, 300, 300);
	AddEntity(ntyBleachers3);

	Entity * ntyBleachers4 = new Entity();
	ntyBleachers4->SetId(7);
	ntyBleachers4->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers4->Translate(63000, 7900, 21000);
	ntyBleachers4->Rotate(0, -90, 0);
	ntyBleachers4->Scale(300, 300, 300);
	AddEntity(ntyBleachers4);

	Entity * ntyBleachers5 = new Entity();
	ntyBleachers5->SetId(8);
	ntyBleachers5->AddModel(objBleachers, 0, 0, 0);
	ntyBleachers5->Translate(70000, 7900, 26000);
	ntyBleachers5->Rotate(0, -160, 0);
	ntyBleachers5->Scale(300, 300, 300);
	AddEntity(ntyBleachers5);

	// Grass
	Texture * texGrass = new Texture();
	LoadTexture("data/grassPlane.raw", texGrass, 512, 512);
	AddTexture(texGrass);
	GenerateTrackPlane(499, texGrass);

	// Finish Line
	Texture * texFinishLine = new Texture();
	LoadTexture("data/models/finishLineBake.raw", texFinishLine, 1024, 1024);
	AddTexture(texFinishLine);

	StaticModel * objFinishLine = new StaticModel();
	LoadObjFile("data/models/finishLineBake.obj", objFinishLine);
	objFinishLine->LoadToCalllist(504);
	objFinishLine->SetTexture(texFinishLine);
	AddModel(objFinishLine);

	Entity * ntyFinishLine = new Entity();
	ntyFinishLine->SetId(9);
	ntyFinishLine->AddModel(objFinishLine, 0, 0, 0);
	ntyFinishLine->Translate(50500, 7700, 34000);
	ntyFinishLine->Rotate(0, 90, 0);
	ntyFinishLine->Scale(300, 300, 500);
	AddEntity(ntyFinishLine);

}

void AssetManager::AddModel(StaticModel * model)
{
	m_models.Insert(model);
}

void AssetManager::AddTexture(Texture * texture)
{
	m_textures.Insert(texture);
}

void AssetManager::AddEntity(Entity * entity)
{
	m_entities.Insert(entity);
}

void AssetManager::RenderLoadedEntities()
{
	glPushMatrix();
	glTranslatef(30136, 7450, 10000);
	glBindTexture(GL_TEXTURE_2D, m_trackPlaneTex->GetTextureId());
	glCallList(499);
	glPopMatrix();
	m_entities.InOrderTraversal(RenderEntityCallback);
}

void AssetManager::UnloadAll()
{
	m_textures.InOrderTraversal(UnloadTextureCallback);
	m_models.InOrderTraversal(UnloadModelCallback);
	m_entities.InOrderTraversal(UnloadEntityCallback);
}

void AssetManager::RenderEntityCallback(Entity * entity)
{
	entity->Render();
}

void AssetManager::UnloadEntityCallback(Entity * entity)
{

}

void AssetManager::UnloadModelCallback(StaticModel * model)
{

}

void AssetManager::UnloadTextureCallback(Texture * texture)
{

}

void AssetManager::GenerateTrackPlane(int listId, Texture * tex)
{
	const float SIZE = 512;
	const float PLANE_SIZE = 500;

	m_trackPlaneTex = tex;

	glNewList(listId, GL_COMPILE);
	glBegin(GL_TRIANGLES);

	for (int x = 0; x < PLANE_SIZE; x++)
		for (int y = 0; y < PLANE_SIZE; y++)
		{
			glTexCoord2f(0, 0);
			glVertex3f((x * SIZE), 0, (y * SIZE));
			glTexCoord2f(1, 0);
			glVertex3f((x * SIZE) + SIZE, 0, (y * SIZE));
			glTexCoord2f(1, 1);
			glVertex3f((x * SIZE) + SIZE, 0, (y * SIZE) + SIZE);

			glTexCoord2f(0, 0);
			glVertex3f((x * SIZE), 0, (y * SIZE));
			glTexCoord2f(1, 1);
			glVertex3f((x * SIZE) + SIZE, 0, (y * SIZE) + SIZE);
			glTexCoord2f(0, 1);
			glVertex3f((x * SIZE), 0, (y * SIZE) + SIZE);

		}

	glEnd();
	glEndList();
}