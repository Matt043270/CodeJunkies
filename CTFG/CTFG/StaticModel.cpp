#include "StaticModel.h"

StaticModel::StaticModel(vector<Vertex> newVertex, vector<int> newInts)
{
	m_verticies = newVertex;
	m_indexes = newInts;
	LoadToVAO();
}

StaticModel::StaticModel()
{

}

StaticModel::~StaticModel()
{
	//glDeleteVertexArrays(1, &m_vaoId);
	vector<GLuint>::iterator vboIter;
	for (vboIter = m_vboIds.begin(); vboIter < m_vboIds.end(); vboIter++)
	{
		//glDeleteVertexArrays(1, &(*vboIter));
	}
}

void StaticModel::LoadToVAO()
{
	glGenVertexArrays(1, &m_vaoId);
	glBindVertexArray(m_vaoId);

	// Indice Buffer Object
	GLuint ibVboId;
	glGenBuffers(1, &ibVboId);
	m_vboIds.push_back(ibVboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibVboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes.size() * sizeof(int), &m_indexes.front(), GL_STATIC_DRAW);

	// Positions Buffer Object
	GLuint vbVboId;
	glGenBuffers(1, &vbVboId);
	m_vboIds.push_back(vbVboId);
	glBindBuffer(GL_ARRAY_BUFFER, vbVboId);
	vector<float> buffer;
	LoadVertexDataToVector(m_verticies, buffer, VT_POSITION);
	glBufferData(GL_ARRAY_BUFFER, m_verticies.size() * sizeof(float) * 3, &buffer.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);

	// Texture Buffer Object
	GLuint tVboId;
	glGenBuffers(1, &tVboId);
	m_vboIds.push_back(tVboId);
	glBindBuffer(GL_ARRAY_BUFFER, tVboId);
	buffer.clear();
	LoadVertexDataToVector(m_verticies, buffer, VT_TEXCOORD);
	glBufferData(GL_ARRAY_BUFFER, m_verticies.size() * sizeof(float) * 2, &buffer.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);



	//Unbind VAO
	glBindVertexArray(0);
}

void StaticModel::BindVertexAttribArray()
{
	glBindVertexArray(m_vaoId);
}

int StaticModel::GetIndiceCount()
{
	return m_indexes.size();
}

void StaticModel::LoadVertexDataToVector(vector<Vertex> vertData, vector<float> &buffer, VertexType type)
{
	vector<Vertex>::iterator vertIter;
	for (vertIter = vertData.begin(); vertIter < vertData.end(); vertIter++)
	{
		Position pos = vertIter->pos;
		Normal norm = vertIter->norm;
		TexCoord tc = vertIter->tex;
		switch (type)
		{
		case VT_POSITION:
			buffer.push_back(pos.x);
			buffer.push_back(pos.y);
			buffer.push_back(pos.z);
			break;
		case VT_NORMAL:
			buffer.push_back(norm.x);
			buffer.push_back(norm.y);
			buffer.push_back(norm.z);
			break;
		case VT_TEXCOORD:
			buffer.push_back(tc.x);
			buffer.push_back(tc.y);
			cout << "Tex Coord: X-" << tc.x << " Y-" << tc.y << endl;
			break;
		}
	}
	
}

void StaticModel::LoadModelFromFile(string filename, StaticModel &model)
{

}