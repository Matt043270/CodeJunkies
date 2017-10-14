#include "SkyBox.h"

SkyBox::SkyBox()
{

}

void SkyBox::Initialize(std::string ffront, std::string fback, std::string fleft, std::string fright, std::string fup, std::string fdown)
{
	m_front = new Texture();
	m_back = new Texture();
	m_left = new Texture();
	m_right = new Texture();
	m_up = new Texture();
	m_down = new Texture();
	AssetManager::LoadTexture(ffront, m_front, 512, 512, true);
	AssetManager::LoadTexture(fback, m_back, 512, 512, true);
	AssetManager::LoadTexture(fleft, m_left, 512, 512, true);
	AssetManager::LoadTexture(fright, m_right, 512, 512, true);
	AssetManager::LoadTexture(fup, m_up, 512, 512, true);
	AssetManager::LoadTexture(fdown, m_down, 512, 512, true);

	glNewList(1000, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1, 1);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(0, 0);
		glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();
	glEndList();

	glNewList(1001, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 1);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(0, 0);
		glVertex3f(0.5f, 0.5f, 0.5f);
	glEnd();
	glEndList();

	glNewList(1002, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 1);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	glEndList();

	glNewList(1003, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(1, 1); 
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glEndList();

	glNewList(1004, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0, 0);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0, 1);
		glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();
	glEndList();

	glNewList(1005, GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2f(0, 1);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 1);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2f(1, 0);
		glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();
	glEndList();
}

void SkyBox::Render(Camera &c)
{

	glPushMatrix();
	glLoadIdentity();
	gluLookAt(
		0, 0, 0, 
		c.GetLookLR(), c.GetLookUD(), c.GetLookFB(),
		0, 1, 0
	);

	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_BLEND);



	glBindTexture(GL_TEXTURE_2D, m_front->GetTextureId());
	glCallList(1000);
	
	glBindTexture(GL_TEXTURE_2D, m_left->GetTextureId());
	glCallList(1001);
	
	glBindTexture(GL_TEXTURE_2D, m_back->GetTextureId());
	glCallList(1002);
	
	glBindTexture(GL_TEXTURE_2D, m_right->GetTextureId());
	glCallList(1003);

	glBindTexture(GL_TEXTURE_2D, m_up->GetTextureId());
	glCallList(1004);

	glBindTexture(GL_TEXTURE_2D, m_down->GetTextureId());
	glCallList(1005);

	glPopAttrib();
	glPopMatrix();
}