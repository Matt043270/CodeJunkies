#ifndef STATICMODEL_H
#define STATICMODEL_H

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>

struct Position
{
	float x, y, z;
	Position()
	{

	}
	Position(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};

struct Normal
{
	float x, y, z;
	Normal()
	{

	}
	Normal(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};

struct TexCoord
{
	float x, y;
	TexCoord()
	{

	}
	TexCoord(float newX, float newY)
	{
		x = newX;
		y = newY;
	}
};

enum VertexType
{
	VT_POSITION,
	VT_NORMAL,
	VT_TEXCOORD
};

struct Vertex
{
	Position pos;
	Normal norm;
	TexCoord tex;
	Vertex(Position newPos, Normal newNormal, TexCoord newTexCoord)
	{
		pos = newPos;
		norm = newNormal;
		tex = newTexCoord;
	}
	Vertex(float x, float y, float z, float nx, float ny, float nz, float tx, float ty)
	{
		Position newPos(x, y, z);
		Normal newNorm(nx, ny, nz);
		TexCoord newTexCoord(tx, ty);
		pos = newPos;
		norm = newNorm;
		tex = newTexCoord;
	}
};

using namespace std;

class StaticModel
{
public:
	StaticModel();
	StaticModel(vector<Vertex> newVerticies, vector<int> newInts);
	~StaticModel();
	void BindVertexAttribArray();
	int GetIndiceCount();
	static void LoadModelFromFile(string filename, StaticModel &model);
private:
	void LoadToVAO();
	void LoadVertexDataToVector(vector<Vertex> vertData, vector<float> &buffer, VertexType type);
private:
	vector<Vertex> m_verticies;
	vector<int> m_indexes;
	vector<GLuint> m_vboIds;
	GLuint m_vaoId;
};

#endif