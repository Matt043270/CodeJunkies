#include "FuelLoader.h"





FuelLoader::~FuelLoader()
{

}


FuelLoader::FuelLoader()
{
	int fuelID = 8;

	Texture * texFuel = new Texture;
	AssetManager::LoadTexture("data/models/fuelBake.raw", texFuel, 1024, 1024);
	m_assetManager.AddTexture(texFuel);

	StaticModel * objFuel = new StaticModel();
	AssetManager::LoadObjFile("data/models/fuel.obj", objFuel);
	objFuel->LoadToCalllist(504);
	objFuel->SetTexture(texFuel);
	m_assetManager.AddModel(objFuel);


	if (readInFile("data/fuelPoints.txt") == 0)
	{
		std::cout << "Problem reading in fuel locations" << std::endl;
	}

	std::vector<point>::iterator iter;
	int id = 20;
	for (iter = fuelLocation.begin(); iter != fuelLocation.end(); iter++)
	{
		EntityFuel * tempFuel = new EntityFuel();
		tempFuel->SetId(id++);
		tempFuel->AddModel(objFuel, 0, 0, 0);
		tempFuel->SetPosition(fuelPointA.x, fuelPointA.y, fuelPointA.z);
		tempFuel->Rotate(0, 0, 0);
		tempFuel->Scale(100, 100, 100);
		fuelVector.push_back(tempFuel);
	}
}

void FuelLoader::RenderFuel()
{
	std::vector<EntityFuel*>::iterator iter;

	for (iter = fuelVector.begin(); iter != fuelVector.end(); iter++)
	{
		EntityFuel * fuel = *iter;
		fuel->Render();
	}
}


bool FuelLoader::readInFile(std::string fileString)
{
	std::ifstream infile(fileString);
	std::string line;
	std::stringstream ss;
	double tempx, tempy, tempz;
	point tempPoint;

	if (!infile)
	{
		return false;
	}

	while (getline(infile, line))
	{
		ss.clear();

		ss << line;

		ss >> tempx >> tempy >> tempz;

		tempPoint.x = tempx;
		tempPoint.y = tempy;
		tempPoint.z = tempz;

		fuelLocation.push_back(tempPoint);

	}

	return true;
}