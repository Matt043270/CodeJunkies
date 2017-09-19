#ifndef TEXTURE_H
#define TEXTURE_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

class Texture
{
public:
	Texture();
	Texture(string filepath);
	void BindTexture();
private:
	void LoadBMP(string filepath);
	void LoadDataToGL();
private:
	GLuint m_textureId;
	int m_width, m_height, m_size;
	char * m_dataPointer;
};

#endif