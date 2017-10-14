#ifndef SKYBOX_H
#define SKYBOX_H

#include <string>
#include "AssetManager.h"
#include "Texture.h"
#include "camera.h"

class SkyBox
{
public:
	SkyBox();

	void Initialize(std::string front, std::string back, std::string left, std::string right, std::string up, std::string down);
	void Render(Camera &c);
private:

private:
	Texture * m_front;
	Texture * m_back;
	Texture * m_left;
	Texture * m_right;
	Texture * m_up;
	Texture * m_down;
};

#endif