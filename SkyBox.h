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

		/**
		 * Initializes the skybox.
		 * @param[in] front The path to the front texture
		 * @param[in] back The path to the back texture
		 * @param[in] left The path to the left texture
		 * @param[in] right The path to the right texture
		 * @param[in] up The path to the up texture
		 * @param[in] down The path to the down texture
		 */
	void Initialize(std::string front, std::string back, std::string left, std::string right, std::string up, std::string down);
		/**
		 * Renders the skybox using the values from the given camera.
		 * @param[inout] c The camera.
		 */
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