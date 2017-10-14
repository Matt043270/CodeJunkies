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
	LoadTexture("data/models/imagemapHallway.raw", texHallway, 2048, 1024);
	AddTexture(texHallway);

	StaticModel * objHallway = new StaticModel();
	LoadObjFile("data/models/hallway.obj", objHallway);
	objHallway->LoadToCalllist(300);
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
	LoadTexture("data/models/imagemapTrack.raw", texTrack, 1024, 512);
	AddTexture(texTrack);

	StaticModel * objTrack = new StaticModel();
	LoadObjFile("data/models/track.obj", objTrack);
	objTrack->LoadToCalllist(301);
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
	//LoadTexture("data/models/kartRedBaked.raw", texKart, 2048, 2048);
	LoadTexture("data/models/Trex.raw", texKart, 512, 512);
	AddTexture(texKart);

	StaticModel * objKart = new StaticModel();
	//LoadObjFile("data/models/kartRedBaked.obj", objKart);
	LoadObjFile("data/models/trex.obj", objKart);
	objKart->LoadToCalllist(302);
	objKart->SetTexture(texKart);
	AddModel(objTrack);

	EntityKart * ntyKart = new EntityKart();
	ntyKart->SetId(3);
	ntyKart->AddModel(objKart, 0, 0, 0);
	ntyKart->Translate(51136, 7750, 40000);
	ntyKart->Rotate(0, 200, 0);
	ntyKart->Scale(100, 100, 100);
	ntyKart->Initialize();
	AddEntity(ntyKart);

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