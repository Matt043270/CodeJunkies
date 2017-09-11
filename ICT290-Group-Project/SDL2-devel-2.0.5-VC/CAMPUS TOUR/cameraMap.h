//  cameraMap.h
//  Header file for the cameraMap class
//  Displays a map and welcome screen in 2D on the screen
//  
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef CAMERA_MAP_H
#define CAMERA_MAP_H

#include <freeglut.h>

//--------------------------------------------------------------------------------------

/**
@class CameraMap
@brief Displays a map and welcome screen in 2D on the screen

@author Shay Leary
@version 01
@date APR05

@author Team CodeJunkies
@version 02
@date 05SEP17

*/
class CameraMap
{
public:
	CameraMap() {};
	virtual ~CameraMap() {};

	//----------------------------------------------------------------------------------

	/**
	@brief Displays the map

	@param screenWidth - The width of the screen
	@param screenHeight - The height of the screen
	@param xPos - The position along the X axis
	@param zPos - The position along the Z axis
	@param tempImage - The image to display

	@return void
	*/
	void DisplayMap(const int & screenWidth, const int & screenHeight,
		const GLdouble & xPos, const GLdouble & zPos,
		const GLuint & tempImage);

	/**
	@brief Displays the welcome and exit screen

	@param screenWidth - The width of the image
	@param screenHeight - The height of the image
	@param tempExit - Determine whether to display the welcome or the exit screen
	@param tempImage - The image to display

	@return void
	*/
	void DisplayWelcomeScreen(const int & screenWidth, const int & screenHeight,
		const int & tempExit, const GLuint & tempImage);

	/**
	@brief Display the "Area not modelled" message

	@param screenWidth - The width of the image
	@param screenHeight - The height of the image
	@param tempImage - The image to display

	@return void
	*/
	void DisplayNoExit(const int & screenWidth, const int & screenHeight,
		const GLuint & tempImage);

private:
	// Privatised copy constructor and assignment operator
	CameraMap(const CameraMap &cam) {};
	CameraMap &operator = (const CameraMap &cam) {};
};

#endif

//--------------------------------------------------------------------------------------