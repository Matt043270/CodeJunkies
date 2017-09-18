#include "Texture.h"

Texture::Texture()
{

}

Texture::Texture(string filepath)
{
	std::cout << "Loading texture: " << filepath << std::endl;
	LoadBMP(filepath);
	LoadDataToGL();
}

void Texture::LoadBMP(string filepath)
{
	FILE * file = fopen(filepath.c_str(), "rb");
	char headerInfo[54];
	if (!file)
	{
		std::cout << filepath << " does not exist." << std::endl;
		return;
	}
	int fileCounter = fread(headerInfo, 1, 54, file);
	if (fileCounter != 54)
	{
		std::cout << "Unknwon Error: " << filepath << std::endl;
		return;
	}

	if (headerInfo[0] != 'B' && headerInfo[1] != 'M')
	{
		std::cout << "Invalid Texture: " << filepath << std::endl;
		return;
	}

	int dataPosition;
	dataPosition = *(int*)&(headerInfo[0x0A]);
	//m_size = *(int*)&(headerInfo[0x22]);
	m_width = *(int*)&(headerInfo[0x12]);
	m_height = *(int*)&(headerInfo[0x16]);

	cout << m_size << " " << m_width << " " << m_height << endl;

	//if (m_size == 0)
	//{
		m_size = m_height * m_width * 3;
	//}
	if (dataPosition == 0)
	{
		dataPosition = 54;
	}

	m_dataPointer = new char[m_size];
	fread(m_dataPointer, 1, m_size, file);
	fclose(file);

	cout << "Loaded!" << std::endl;
}

void Texture::LoadDataToGL()
{
	glGenTextures(1, &m_textureId);
	glBindTexture(GL_TEXTURE_2D, m_textureId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, m_dataPointer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}