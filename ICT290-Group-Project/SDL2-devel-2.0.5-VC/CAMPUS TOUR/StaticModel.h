#ifndef STATICMODEL_H
#define STATICMODEL_H

#include "texturedPolygons.h"
#include "DefineList.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <freeglut.h>

	/**
	* Holds information about a point in 3D space.
	*/
struct Vertex
{
	float x, y, z;
};

	/**
	* Holds infoormation about a triangle. 3 Vertex Indexes, 3 Texture Indexes and 3 Normal Indexes
	*/
struct Face
{
	int v1, t1, n1,
		v2, t2, n2,
		v3, t3, n3;
};

	/**
	* Holds information about the texture coordinates.
	*/
struct TexCoord
{
	float u, v;
};

	/**
	* A class for loading, storing, and rendering the information from a wavefront obj file.
	* @author Mathew Causby
	*/
class StaticModel
{
public:
		/**
		* Default constructor
		*/
	StaticModel();
		/**
		* Default destructor.
		*/
	~StaticModel();

		/**
		* Adds a vertex to model.
		* @param[in] v The vertex to add to the model.
		*/
	void AddVertex(Vertex v);
		/**
		* Adds a face to the model.
		* @param[in] f The face to add to the model.
		*/
	void AddFace(Face f);
		/**
		* Adds a texture coordinate to the model.
		* @param[in] t The texture coordinate to add to the model
		*/
	void AddTextureCoord(TexCoord t);

		/**
		* Loads the stored model data to the specified call list, and saves the id in memory for future rendering.
		* @param[in] callListId The ID of the call list.
		*/
	void LoadToCalllist(int callListId);

		/**
		* Static function to load all the model data from a specified obj file.
		* @param[in] objFile A string containing the location of the obj file to load.
		* @param[out] model A StaticModel object to load the data into.
		*/
	static void LoadObjFile(std::string objFile, StaticModel &model);

		/**
		* Sets the translate coordinates.
		* @param[in] x The x location.
		* @param[in] y The y location.
		* @param[in] z The z location.
		*/
	void Translate(float x, float y, float z);
		/**
		* Sets the rotation of the model.
		* @param[in] x The x rotation.
		* @param[in] y The y rotation.
		* @param[in] z The z rotation.
		*/
	void Rotate(float x, float y, float z);
		/**
		* Sets the scale of the model.
		* @param[in] x The x scale.
		* @param[in] y The y scale.
		* @param[in] z The z scale.
		*/
	void Scale(float x, float y, float z);

		/**
		* Renders the model using the specified texture.
		* @param[in] tex The texture to render onto the model.
		*/
	void Render(GLuint tex);

	GLuint GetCallListId();

	bool operator > (StaticModel &rhs);
	bool operator < (StaticModel &rhs);

		// Test Methods
	void OutputVertex();
	void OutputFace();
private:

private:
		/**
		* A vector containing all the vertexes in the model
		*/
	std::vector<Vertex> m_v;
		/**
		* A vector containing all the faces of the model.
		*/
	std::vector<Face> m_f;
		/**
		* A vector containing all the texture coordinates of the model.
		*/
	std::vector<TexCoord> m_t;
		/**
		* The id of the call list.
		*/
	int m_callListId;
		/**
		* The x, y, and z location of the model
		*/
	float m_x, m_y, m_z;
		/**
		* The x, y, and z rotation of the model
		*/
	float m_xRot, m_yRot, m_zRot;
		/**
		* The x, y, and z scale of the model.
		*/
	float m_xScale, m_yScale, m_zScale;
};

#endif