#ifndef STRUCTDEFS_H
#define STRUCTDEFS_H

	/**
	 * Structure that represents a point in 3D space.
	 */
struct Position
{
	float x, y, z;
	Position() {}
	Position(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};

	/**
	 * Structure that represents a uv map point of a texture
	 */
struct TexCoord
{
	float u, v;
	TexCoord() {}
	TexCoord(float newU, float newV)
	{
		u = newU;
		v = newV;
	}
};

	/**
	 * A structure that represents the normal points of a vertex
	 */
struct Normal
{
	float x, y, z;
	Normal() {}
	Normal(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};

	/**
	 * A structure that represents a Vertex, containing a Position, Normal, and a TexCoord.
	 */
struct Vertex
{
	Position pos;
	Normal norm;
	TexCoord tex;
	Vertex() {}
	Vertex(Position newPos, Normal newNorm, TexCoord newTex)
	{
		pos = newPos;
		norm = newNorm;
		tex = newTex;
	}
};

	/**
	 * A structure that represents a Face of a model, containing 3 Vertex objects, making a single triangle.
	 */
struct Face
{
	Vertex p1, p2, p3;
	Face() {}
	Face(Vertex newP1, Vertex newP2, Vertex newP3)
	{
		p1 = newP1;
		p2 = newP2;
		p3 = newP3;
	}
};

#endif