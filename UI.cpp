#include "UI.h"

int UI::m_height;
int UI::m_width;

void UI::SetScreen(int width, int height)
{
	m_width = width;
	m_height = height;
}

void UI::Draw2DImage(int x, int y, int width, int height, float rotation, Texture * tex)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, m_width, m_height, 0, -1, 10);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 1);
	glRotatef(rotation, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, tex->GetTextureId());
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(0, 0);
		glTexCoord2f(1, 0);
		glVertex2f(width, 0);
		glTexCoord2f(1, 1);
		glVertex2f(width, height);
		glTexCoord2f(0, 1);
		glVertex2f(0, height);
	glEnd();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}