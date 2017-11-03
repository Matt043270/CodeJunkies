#ifndef FUELLOADER_H
#define FUELLOADER_H

#include "AssetManager.h"
#include "StaticModel.h"
#include <vector>

#include<fstream>
#include<sstream>
#include<iostream>
#include<string>

struct point {
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};


class FuelLoader
{
public:

	~FuelLoader();
	bool readInFile(std::string fileString);
	FuelLoader();
	void RenderFuel();

protected:
	std::vector<EntityFuel*> fuelVector;
	std::vector<point> fuelLocation;
	point fuelPointA;
	AssetManager m_assetManager;

};

#endif