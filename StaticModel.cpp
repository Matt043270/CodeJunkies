#include "StaticModel.h"

StaticModel::StaticModel()
{

}

StaticModel::~StaticModel()
{

}

void StaticModel::AddVertex(Vertex v)
{
	m_v.push_back(v);
}

void StaticModel::AddFace(Face f)
{
	m_f.push_back(f);
}

void StaticModel::AddTextureCoord(TexCoord t)
{
	m_t.push_back(t);
}

void StaticModel::LoadToCalllist(int calllist)
{
	using namespace std;
	vector<Face>::iterator facItr;

	glNewList(calllist, GL_COMPILE);
	glBegin(GL_TRIANGLES);

	for (facItr = m_f.begin(); facItr != m_f.end(); facItr++)
	{
		Face f = *facItr;
		glTexCoord2f(m_t[f.t1 - 1].u, m_t[f.t1 - 1].v);
		glVertex3f(m_v[f.v1 - 1].x, m_v[f.v1 - 1].y, m_v[f.v1 - 1].z);
		glTexCoord2f(m_t[f.t2 - 1].u, m_t[f.t2 - 1].v);
		glVertex3f(m_v[f.v2 - 1].x, m_v[f.v2 - 1].y, m_v[f.v2 - 1].z);
		glTexCoord2f(m_t[f.t3 - 1].u, m_t[f.t3 - 1].v);
		glVertex3f(m_v[f.v3 - 1].x, m_v[f.v3 - 1].y, m_v[f.v3 - 1].z);
	}

	glEnd();
	glEndList();
	m_callListId = calllist;
}

void StaticModel::Translate(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void StaticModel::Rotate(float x, float y, float z)
{
	m_xRot = x;
	m_yRot = y;
	m_zRot = z;
}

void StaticModel::Scale(float x, float y, float z)
{
	m_xScale = x;
	m_yScale = y;
	m_zScale = z;
}

void StaticModel::Render()//GLuint tex)
{
	glBindTexture(GL_TEXTURE_2D, m_tex->GetTextureId());
	glCallList(m_callListId);
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "Error: " << gluErrorString(err) << std::endl;
	}
}

void StaticModel::OutputVertex()
{
	std::vector<Vertex>::iterator verItr;
	for (verItr = m_v.begin(); verItr != m_v.end(); verItr++)
	{
		std::cout << "X: " << (*verItr).x << " Y: " << (*verItr).y << " Z: " << (*verItr).z << std::endl;
	}
	std::cout << "Total Vertex Size: " << m_v.size() << std::endl;
}

void StaticModel::OutputFace()
{
	std::vector<Face>::iterator facItr;
	for (facItr = m_f.begin(); facItr != m_f.end(); facItr++)
	{
		std::cout << "Face 1 - V: " << (*facItr).v1 << " T: " << (*facItr).t1 << " N: " << (*facItr).n1 << std::endl;
		std::cout << "Face 2 - V: " << (*facItr).v2 << " T: " << (*facItr).t2 << " N: " << (*facItr).n2 << std::endl;
		std::cout << "Face 3 - V: " << (*facItr).v3 << " T: " << (*facItr).t3 << " N: " << (*facItr).n3 << std::endl << std::endl;
	}
	std::cout << "Total Face Size: " << m_f.size() << std::endl;
}

GLuint StaticModel::GetCallListId()
{
	return m_callListId;
}

bool StaticModel::operator > (StaticModel &rhs)
{
	return (m_callListId > rhs.GetCallListId());
}

bool StaticModel::operator < (StaticModel &rhs)
{
	return (m_callListId < rhs.GetCallListId());
}

void StaticModel::SetTexture(Texture * texture)
{
	m_tex = texture;
}

Texture * StaticModel::GetTexture()
{
	return m_tex;
}