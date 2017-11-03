#include<stdlib.h>
#include <math.h>
#include <freeglut.h>
#include <time.h>

//#include <windows.h> // only used if mouse is required (not portable)
#include "camera.h"
#include "texturedPolygons.h"
#include "DisplayWorld.h"
#include "StaticModel.h"
#include "AssetManager.h"
#include "SkyBox.h"
#include "InputManager.h"
#include "UI.h"

#include "GameManager.h"
#include "ExploreState.h"
#include "PreGameState.h"
#include "GameRunningState.h"

//--------------------------------------------------------------------------------------

#define PI 3.1415962654


int frameCount = 0;
clock_t lastClock = 0;

// ratio of screen
float ratio;

float frame;

// States
GameManager * stateManager;
ExploreState * exploreState;
PreGameState * preGameState;
GameRunningState * gameRunningState;

//AssetManager assetManager;
SkyBox sbMain;

// initializes setting
void myinit();

// display functions
void Display();
void reshape(int w, int h);
void keys(unsigned char key, int x, int y);

// keyboard and mouse functions
void movementKeys(int key, int x, int y);
void releaseKey(int key, int x, int y);
void releaseKeys(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);

void IncrementFrameCount();


//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 500);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(movementKeys);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardUpFunc(releaseKeys);
	glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}

//--------------------------------------------------------------------------------------
//  Initialize Settings
//--------------------------------------------------------------------------------------
void myinit()
{
	// set background (sky colour)
	glClearColor(97.0 / 255.0, 140.0 / 255.0, 185.0 / 255.0, 1.0);

	// set perpsective
	gluLookAt(0.0, 1.75, 0.0,
		0.0, 1.75, -1,
		0.0f, 1.0f, 0.0f);

	stateManager = new GameManager();
	exploreState = new ExploreState();
	exploreState->m_gameManager = stateManager;
	exploreState->Initialize();
	preGameState = new PreGameState();
	preGameState->m_gameManager = stateManager;
	exploreState->AddPreGameState(preGameState);
	stateManager->changeState(exploreState);
	gameRunningState = new GameRunningState();
	preGameState->AddGameRunningState(gameRunningState);
	

	InputManager::GetInstance()->Initialize();

	sbMain.Initialize(
		"data/skybox/FT.data",
		"data/skybox/BK.data",
		"data/skybox/LF.data",
		"data/skybox/RT.data",
		"data/skybox/UP.data",
		"data/skybox/DN.data"
	);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//assetManager.LoadAllAssets();
}

//--------------------------------------------------------------------------------------
//  Main Display Function
//--------------------------------------------------------------------------------------
void Display()
{
	// set the movement and rotation speed according to frame count
	IncrementFrameCount();

	stateManager->peekState()->update(frame);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// DISPLAY TEXTURES
	//enable texture mapping
	glEnable(GL_TEXTURE_2D);
	
	glPushMatrix();

	sbMain.Render(stateManager->peekState()->GetCamera());

	stateManager->peekState()->draw(frame);
	//assetManager.RenderLoadedEntities();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	// clear buffers
	glFlush();
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------
void reshape(int w, int h)
{
	exploreState->SetDimensions(w, h);
	preGameState->SetDimensions(w, h);
	gameRunningState->SetDimensions(w, h);

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 0.1f, 250000);
	glMatrixMode(GL_MODELVIEW);

	UI::SetScreen(w, h);
}

//--------------------------------------------------------------------------------------
// Keyboard Functions
//--------------------------------------------------------------------------------------
void movementKeys(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, true);
}

//--------------------------------------------------------------------------------------
void releaseKey(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, false);
}

//--------------------------------------------------------------------------------------
void keys(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback((int)key, true);
}

//--------------------------------------------------------------------------------------
void releaseKeys(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback((int)key, false);
}

//--------------------------------------------------------------------------------------
//  Mouse Buttons
//--------------------------------------------------------------------------------------
void Mouse(int button, int state, int x, int y)
{
	stateManager->peekState()->MouseClick(button, state, x, y);
}

//--------------------------------------------------------------------------------------
//  Increments frame count used for setting movement speed
//--------------------------------------------------------------------------------------
void IncrementFrameCount()
{
	double t = ((GLdouble)(clock() - lastClock)) / (GLdouble)CLOCKS_PER_SEC;
	frameCount++;

	// reset after t
	if (t > 0.1)
	{
		frame = t / (float)frameCount;
		frameCount = 0;
		lastClock = clock();
	}
}