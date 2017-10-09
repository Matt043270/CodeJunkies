#include "Texture.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

GLuint Texture::GetTextureId()
{
	return m_textureId;
}

void Texture::SetTextureId(GLuint textureId)
{
	m_textureId = textureId;
}

bool Texture::operator > (Texture &rhs)
{
	return m_textureId > rhs.GetTextureId();
}

bool Texture::operator < (Texture &rhs)
{
	return m_textureId < rhs.GetTextureId();
}