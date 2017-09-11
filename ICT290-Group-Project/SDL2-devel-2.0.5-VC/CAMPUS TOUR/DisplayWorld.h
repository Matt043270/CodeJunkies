#ifndef DISPLAYWORLD_H
#define DISPLAYWORLD_H


#include<stdlib.h>
#include <math.h>
#include <freeglut.h>
#include <time.h>



//#include <windows.h> // only used if mouse is required (not portable)
#include "camera.h"
#include "texturedPolygons.h"
#include"DefineList.h"

/**
@class DisplayWorld
@brief Manages all models for Shay's World

Models are created using the block of draw functions, and are rendered using the block of display functions.
Textures are created from raw files and associated with a string as reference.

@author Team CodeJunkies
@version 01
@date 04SEP17
Display and draw functions moved to a separate class, doxygen comments added

*/
class DisplayWorld {

public:
	/**
	@brief Calls all display functions

	@param bool

	@return bool (true if successfull)
	*/
	bool RenderWorld(bool lightsOn);

	/**
	@brief Calls all draw functions

	@return bool (true if successfull)
	*/
	bool DrawWorld();

	/**
	@brief Calls deleteTempImageFromMemory and passes member image as a parameter

	@return void
	*/
	void deleteImageFromMemory();

	/**
	@brief Returns a reference to the welcome texture

	@return GLuint
	*/
	GLuint getWelcomeTex();

	/**
	@brief Returns a reference to the exit texture

	@return GLuint
	*/
	GLuint getExitTex();

	/**
	@brief Returns a reference to the no exit texture

	@return GLuint
	*/
	GLuint getNoExitTex();

	/**
	@brief Returns a reference to the map texture

	@return GLuint
	*/
	GLuint getMapTex();

private:

	/**
	@brief Frees memory by deleting given parameter

	@param unsigned char*

	@return void
	*/
	void deleteTempImageFromMemory(unsigned char* tempImage);
	// functions to display display lists (images) and bind them to a texture

	void DisplayAboveWindowBlock();
	void DisplayBench();
	void DisplayBricks();
	void DisplayChancPosts();
	void DisplayCylinders();
	void DisplayDoorPaving();
	void DisplayDoorPosts();
	void DisplayEntranceSteps();
	void DisplayExtras();
	void DisplayGrass();
	void DisplayLargerTextures();
	void DisplayLibraryPosts();
	void DisplayMainPosts();
	void DisplayPavement();
	void DisplayPhysSciPosts();
	void DisplayPurplePosts();
	void DisplayRedPosts();
	void DisplayRoof();
	void DisplayStepBricks();
	void DisplayLights();
	void DisplayECL();


	// creates display lists
	void DrawGrass();
	void DrawChancPosts();
	void DrawDoorPosts();
	void DrawPurplePosts();
	void DrawRedPosts();
	void DrawMainPosts();
	void DrawAboveWindowBlock();
	void DrawDoorPaving();
	void DrawPhysSciPosts();
	void DrawLibraryPosts();
	void DrawBricks();
	void DrawPavement();
	void DrawExtras();
	void DrawRoof();
	void DrawEntranceSteps();
	void DrawLargerTextures();
	void DrawLights();
	void DrawBench();
	void DrawCylinders();
	void DrawAngledRoofBeam(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);
	void DrawAngledRoofBeam2(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);
	void DrawStepBricks();
	void DrawMapExit();
	void DrawECL();

	/**
	@brief Loads each texture and associates them with a string

	@return void
	*/
	void CreateTextures();

	TexturedPolygons tp;

	// varibles used for tarnslating graphics etc
	GLdouble step, step2, stepLength;

	// Glut Cylinder
	GLUquadricObj *glu_cylinder;

	// Stores raw image file
	unsigned char* image = NULL;


};

#endif 
