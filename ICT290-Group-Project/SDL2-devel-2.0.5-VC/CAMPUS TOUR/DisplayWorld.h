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



class DisplayWorld {

public:
		/**
		@brief Calls all display functions

		@param bool
		@retval bool (true if successfull)
		*/
	 bool RenderWorld(bool lightsOn);

		/**
		@brief calls all draw functions

		@retval bool (true if successfull)
		*/
	bool DrawWorld();

		/**
		@brief calls deleteTempImageFromMemory
		and passes member image as a parameter
		*/
	void deleteImageFromMemory();

		/**
		@brief returns a reference to the welcome texture

		@retval GLuint
		*/
	GLuint getWelcomeTex();

		/**
		@brief returns a reference to the exit texture

		@retval GLuint
		*/
	GLuint getExitTex();

		/**
		@brief returns a reference to the no exit texture

		@retval GLuint
		*/
	GLuint getNoExitTex();

		/**
		@brief returns a reference to the map texture

		@retval GLuint
		*/
	GLuint getMapTex();

	GLuint GetTexture(int tex);

private:

		/**
		@brief frees memory by deleting given parameter

		@param unsigned char*
		*/
	void deleteTempImageFromMemory(unsigned char* tempImage);
	// functions to display display lists (images) and bind them to a texture

		/**
		@brief 
		*/
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
		/**
		@brief
		*/
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
		@brief loads each texture and associates them with a string
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
