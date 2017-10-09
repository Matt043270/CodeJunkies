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

void AssetManager::LoadTexture(std::string texFile, Texture & tex, int width, int height)
{
	using namespace std;
	ifstream iFile(texFile);
	string file;
	char bit;

	while (iFile.get(bit))
	{
		file += bit;
	}

	const char * data = file.c_str();
	GLuint texId;
	glGenTextures(1, &texId);

	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	cout << texId;
	tex.SetTextureId(texId);

}

void AssetManager::LoadAllAssets()
{
	Texture texHallway;
	LoadTexture("data/models/imagemapHallway.raw", texHallway, 2048, 1024);
	AddTexture(&texHallway);

	StaticModel * objHallway = new StaticModel();
	LoadObjFile("data/models/hallway.obj", objHallway);
	AddModel(objHallway);

	Entity * ntyHallway = new Entity();
	ntyHallway->AddModel(objHallway, 0, 0, 0);
	ntyHallway->SetPosition(34350, 10000, 42097);
	ntyHallway->SetRotation(0, 180, 0);
	ntyHallway->Scale(13.5f, 8.8f, 9.9f);
	AddEntity(ntyHallway);
	
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