#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::AddModel(StaticModel * model, float offX, float offY, float offZ)
{
	Offset os(offX, offY, offZ);
	OffsetModel om(os, model);
	m_models.push_back(om);

}

void Entity::Translate(float x, float y, float z)
{
	m_x += x;
	m_y += y;
	m_z += z;
}

void Entity::Scale(float x, float y, float z)
{
	m_xscale = x;
	m_yscale = y;
	m_zscale = z;
}

void Entity::Rotate(float x, float y, float z)
{
	m_xr += x;
	m_yr += y;
	m_zr += z;

	if (m_xr > 360)
		m_xr -= 260;
	if (m_yr > 360)
		m_yr -= 260;
	if (m_zr > 360)
		m_zr -= 260;

}

void Entity::SetPosition(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void Entity::SetRotation(float x, float y, float z)
{
	m_xr = x;
	m_yr = y;
	m_zr = z;
}

void Entity::SetId(int id)
{
	m_id = id;
}

int Entity::GetId()
{
	return m_id;
}

bool Entity::operator < (Entity &rhs)
{
	return (m_id < rhs.GetId());
}

bool Entity::operator > (Entity &rhs)
{
	return (m_id > rhs.GetId());
}

void Entity::Render()
{
	std::vector<OffsetModel>::iterator iter;

	glPushMatrix();

	glTranslatef(m_x, m_y, m_z);
	glRotatef(m_xr, 1, 0, 0);
	glRotatef(m_yr, 0, 1, 0);
	glRotatef(m_zr, 0, 0, 1);
	glScalef(m_xscale, m_yscale, m_zscale);

	for (iter = m_models.begin(); iter != m_models.end(); iter++)
	{
		Offset os = (*iter).os;
		StaticModel * model = (*iter).model;
		glPushMatrix();
		glTranslatef(os.x, os.y, os.z);
		model->Render();
		glPopMatrix();
	}

	glPopMatrix();
}