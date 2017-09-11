//  texturedPolygon.h
//  Header file for the texturedPolygon class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef TEXTURE_POLYGON_H
#define TEXTURE_POLYGON_H

//--------------------------------------------------------------------------------------

#include <freeglut.h>
#include <stdio.h>	// should really be using c++, but didn't get time to change
#include <stdlib.h>

//--------------------------------------------------------------------------------------

/**
@class TexturedPolygons
@brief Manages textures for Shay's World

Textures are loaded and returned.
Textures are mapped to vertices, and display lists are created.

@author Shay Leary
@version 01
@date 03MAR

@author Team CodeJunkies
@version 02
@date 04SEP17, doxygen comments added

*/

class TexturedPolygons
{
public:

	TexturedPolygons() {}
	virtual ~TexturedPolygons() { Clear(); }

	/**
	@brief Returns the texture at given index

	@param tempIndex - Index number of the desired texture
	@return Gluint - texture
	*/
	GLuint GetTexture(const int & tempIndex) { return m_texture[tempIndex]; }

	/**
	@brief Loads a raw image into memory

	@param *filename - Filename of the raw image file
	@param imgWidth - Pixel width of the texture
	@param imgHeight - Pixel height of the texture

	@return GLubyte* - image
	*/
	GLubyte* LoadTexture(char *filename, int imgWidth, int imgHeight);

	/**
	@brief Sets the number of textures to be used

	@param &textureNo - Number of textures to be used

	@return void
	*/
	void SetTextureCount(const int &textureNo);

	/**
	@brief Creates texture and sets the requires values for texture mapping

	@param textureNo - Index number of the texture
	@param image - Image data
	@param imgWidth - Pixel width of the texture
	@param imgHeight - Pixel height of the texture

	@return void
	*/
	void CreateTexture(int textureNo, unsigned char* image, int imgWidth, int imgHeight);

	/**
	@brief Calls function to create display list to contain image

	@param &XYZ - Determines the type of texture list to create
	@param &listNo - The index number of the new texture list
	@param &xImgSize - The first dimension of the new texture list
	@param &zImgSize - The second dimension of the new texture list
	@param &xStart - The texture start location on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &zStart - The texture start location on the Z axis
	@param &xTimes - The number of times to repeat the image along the first dimension
	@param &zTimes - The number of times to repeat the image along the second dimension

	@return void
	*/
	void CreateDisplayList(const int &XYZ, const int &listNo,
		const GLdouble &xImgSize, const GLdouble &zImgSize,
		const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
		const GLdouble &xTimes, const GLdouble &zTimes);

	/**
	@brief Creates display list for images larger than the world scale - YZ axis

	@param &listNo - The index number of the new texture list
	@param &xStart - The texture start location on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &ySize - The size of the plane on the Y axis
	@param &zStart - The texture start location on the Z axis
	@param &zSize - The size of the plane on the Z axis
	@param &yImgSize - The size of the image on the Y axis
	@param &zImgSize - The size of the image on the Z axis

	@return void
	*/
	void CreateYtoZWindowList(const int &listNo, const GLdouble &xStart,
		const GLdouble &yStart, const GLdouble &ySize,
		const GLdouble &zStart, const GLdouble &zSize,
		const GLdouble &yImgSize, const GLdouble &zImgSize);

	/**
	@brief Creates display list for images larger than the world scale - XY axis

	@param &listNo - The index number of the new texture list
	@param &zStart - The texture start location on the Z axis
	@param &xStart - The texture start location on the X axis
	@param &xSize - The size of the plane on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &ySize - The size of the plane on the Y axis
	@param &xImgSize - The size of the image on the X axis
	@param &yImgSize - The size of the image on the Y axis

	@return void
	*/
	void CreateXtoYWindowList(const int &listNo, const GLdouble &zStart,
		const GLdouble &xStart, const GLdouble &xSize,
		const GLdouble &yStart, const GLdouble &ySize,
		const GLdouble &xImgSize, const GLdouble &yImgSize);

	// used to create display lists where image is on an angle
	/**
	@brief Creates a display list where the plane is on an angle

	@param &listNo - The index number of the new texture list
	@param &imageWidth - The width of the image
	@param &imageHeight - The height of the image
	@param &x1 - The location of the first vertex - X axis
	@param &x2 - The location of the second vertex - X axis
	@param &x3 - The location of the third vertex - X axis
	@param &x4 - The location of the fourth - vertex - X axis
	@param &y1 - The location of the first vertex - Y axis
	@param &y2 - The location of the second vertex - Y axis
	@param &y3 - The location of the third vertex - Y axis
	@param &y4 - The location of the fourth vertex - Y axis
	@param &z1 - The location of the first vertex - Z axis
	@param &z2 - The location of the second vertex - Z axis
	@param &z3 - The location of the third vertex - Z axis
	@param &z4 - The location of the fourth vertex - Z axis
	@param &smallestX - Determines angle on the XZ, XY, or the YZ axis
	@param &smallestZ - Determines angle on the XZ, XY, or the YZ axis

	@return void
	*/
	void CreateAngledPolygon(const int &listNo,
		const GLdouble &imageWidth, const GLdouble &imageHeight,
		const GLdouble &x1, const GLdouble &x2,
		const GLdouble &x3, const GLdouble &x4,
		const GLdouble &y1, const GLdouble &y2,
		const GLdouble &y3, const GLdouble &y4,
		const GLdouble &z1, const GLdouble &z2,
		const GLdouble &z3, const GLdouble &z4,
		const int &smallestX, const int &smallestZ);

private:
	// pointer to display list
	GLuint *m_texture;

	/**
	@brief Loads a raw image file and creates a texture image

	@param filename - The filename of the raw image file
	@param width - The width of the texture image file
	@param height - The height of the texture image file

	@return GLubyte* - Image data
	*/
	GLubyte* LoadRawImageFile(char* filename, int width, int height);

	/**
	@brief Clears the memory used to store textures when program terminates

	@return void
	*/
	void Clear();

	/**
	@brief Creates a display list to contain an image on the XZ axis

	@param &xImgSize - The size of the image on the X axis
	@param &zImgSize - The size of the image on the Z axis
	@param &xStart - The texture start location on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &zStart - The texture start location on the Z axis
	@param &xTimes - The amount to scale the image by on the X axis
	@param &zTimes - The amount to scale the image by on the Z axis

	@return void
	*/
	void CreateXtoZTextureList(const GLdouble &xImgSize, const GLdouble &zImgSize,
		const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
		const GLdouble &xTimes, const GLdouble &zTimes);

	/**
	@brief Creates a display list to contain an image on the XY axis

	@param &xImgSize - The size of the image on the X axis
	@param &yImgSize - The size of the image on the Y axis
	@param &xStart - The texture start location on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &zStart - The texture start location on the Z axis
	@param &xTimes - The amount to scale the image by on the X axis
	@param &yTimes - The amount to scale the image by on the Y axis

	@return void
	*/
	void CreateXtoYTextureList(const GLdouble &xImgSize, const GLdouble &yImgSize,
		const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
		const GLdouble &xTimes, const GLdouble &yTimes, const bool &flip);

	/**
	@brief Creates a display list to contain an image on the YZ axis

	@param &yImgSize - The size of the image on the Y axis
	@param &zImgSize - The size of the image on the Z axis
	@param &xStart - The texture start location on the X axis
	@param &yStart - The texture start location on the Y axis
	@param &zStart - The texture start location on the Z axis
	@param &yTimes - The amount to scale the image by on the Y axis
	@param &zTimes - The amount to scale the image by on the Z axis

	@return void
	*/
	void CreateYtoZTextureList(const GLdouble &yImgSize, const GLdouble &zImgSize,
		const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
		const GLdouble &yTimes, const GLdouble &zTimes, const bool &flip);

	/**
	@brief Determines how angled images are displayed

	@param xzImage1 - First vertex
	@param xzImage2 - Second vertex
	@param xzImage3 - Third vertex
	@param xzImage4 - Fourth vertex
	@param imageSize - Size of the image

	@return void
	*/
	void CreateTextureScale(GLdouble & xzImage1, GLdouble & xzImage2,
		GLdouble & xzImage3, GLdouble & xzImage4,
		const GLdouble &imageSize);

	//----------------------------------------------------------------------------------

	// Privatised copy constructor and assignment operator
	TexturedPolygons(const TexturedPolygons &tp) {};
	TexturedPolygons &operator = (const TexturedPolygons &tp) {};
};

#endif

//----------------------------------------------------------------------------------