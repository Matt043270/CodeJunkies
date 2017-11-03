#ifndef UI_H
#define UI_H

#include "Texture.h"

class UI
{
public:
		/**
		 * Sets the current screen dimensions
		 * @param[in] width THe width of the screen
		 * @param[in] height THe height of the screen
		 */
	static void SetScreen(int width, int height);
		/**
		 * Draws a texture to the screen.
		 * @param[in] x The x position to draw the texture.
		 * @param[in] y THe y position to draw the texture.
		 * @param[in] width THe width of the UI element
		 * @param[in] height The height of the UI element.
		 * @param[inout] tex THe texture to draw.
		 */
	static void Draw2DImage(int x, int y, int width, int height, float rotation, Texture * tex);

private:

private:
	static int m_width, m_height;
};

#endif