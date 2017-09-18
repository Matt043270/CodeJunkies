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

void StaticModel::LoadObjFile(std::string objFile, StaticModel &model)
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

			model.AddVertex(v);
		}

		// Texture
		if (line.compare(0, vt.length(), vt) == 0)
		{
			string pre, u, v;
			ss >> pre >> u >> v;
			TexCoord tex;

			tex.u = strtof(u.c_str(), NULL);
			tex.v = 1 - (strtof(v.c_str(), NULL));
			model.AddTextureCoord(tex);
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

			model.AddFace(f);

		}
		ss.clear();
	}
	file.close();

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

void StaticModel::Render(GLuint tex)
{
	glPushMatrix();

	glTranslatef(m_x, m_y, m_z);
	glRotatef(m_xRot, 1, 0, 0);
	glRotatef(m_yRot, 0, 1, 0);
	glRotatef(m_zRot, 0, 0, 1);
	glScalef(m_xScale, m_yScale, m_zScale);
	glBindTexture(GL_TEXTURE_2D, tex);
	glCallList(m_callListId);
	glPopMatrix();
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