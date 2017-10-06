#ifndef TEXTURE_H
#define TEXTURE_H

#include <freeglut.h>

class Texture
{
public:
		/**
		 * Default constructor
		 */
	Texture();
		/**
		 * Default destructor
		 */
	~Texture();

	GLuint GetTextureId();
	bool operator > (const Texture &rhs);
	bool operator < (const Texture &rhs);
private:
	
private:
		/**
		 * The texture ID
		 */
	GLuint m_textureId;
};


#endif