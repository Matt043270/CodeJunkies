
#include <freeglut.h>
#include <iostream>

#include "InputManager.h"
#include "camera.h"

Camera cam;

InputManager::InputManager()
{
	imXrot = 0.0;
	imYrot = 0.0;
	imMaxAngle = 45.0;
	imMinAngle = 0.0;
	imMouseClicked = false;
	imLastx = glutGet(GLUT_WINDOW_WIDTH) / 2.0f;
	imLasty = glutGet(GLUT_WINDOW_HEIGHT) / 2.0f;

	//set key states to false (not pressed)
	for(int i=0; i<256; i++)
	{
		imKeyStates[i] = false;
	}

	//set special key states (arrow keys) to false (not pressed)
	for(int i=0; i<4; i++)
	{
		imSpecialKeyStates[i] = false;
	}
}


void InputManager::SpecialKey(int key, int x, int y) 
{
	switch (key)
	{
		case GLUT_KEY_LEFT :
			imSpecialKeyStates[0] = true;
			break;

		case GLUT_KEY_RIGHT :
			imSpecialKeyStates[1] = true;
			break;

		case GLUT_KEY_UP : 
			imSpecialKeyStates[2] = true;
			break;

		case GLUT_KEY_DOWN : 
			imSpecialKeyStates[3] = true;
			break;
	}
}


void InputManager::SpecialKeyUp(int key, int x, int y) 
{
	switch (key)
	{
		case GLUT_KEY_LEFT :
			imSpecialKeyStates[0] = false;
			break;

		case GLUT_KEY_RIGHT :
			imSpecialKeyStates[1] = false;
			break;

		case GLUT_KEY_UP : 
			imSpecialKeyStates[2] = false;
			break;

		case GLUT_KEY_DOWN : 
			imSpecialKeyStates[3] = false;
			break;
	}
}


void InputManager::Keyboard(unsigned char key, int x, int y)
{
	imKeyStates[key] = true; // Set the state of the current key to pressed
}


void InputManager::KeyboardUp(unsigned char key, int x, int y)
{
	imKeyStates[key] = false; // Set the state of the current key to not pressed
}


void InputManager::Mouse(int button, int state, int x, int y)
{
	imLastx = (float)x; //set lastx to the current x position
	imLasty = (float)y; //set lasty to the current y position
	
	if((button == GLUT_LEFT_BUTTON) || (button == GLUT_RIGHT_BUTTON)) 
	{
		imMouseClicked = (state == GLUT_DOWN);
		if(state == GLUT_DOWN)
		{
			glutSetCursor(GLUT_CURSOR_NONE);
		}
		else
		{
			glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2); //rest the mouse point to center of window
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
	}
}


void InputManager::MouseMotion(int x, int y)
{
	imDiffx = 0;// = x-lastx; //check the difference between the current x and the last x position
	imDiffy = 0;// = y-lasty; //check the difference between the current y and the last y position

	if(imMouseClicked)
	{
		imDiffx = x-(int)imLastx; //check the difference between the current x and the last x position
		imDiffy = y-(int)imLasty; //check the difference between the current y and the last y position
	}

	imLastx = (float)x; //set lastx to the current x position
	imLasty = (float)y; //set lasty to the current y position

	imXrot += (float) imDiffy; //set the xrot to xrot with the addition of the difference in the y position
	imYrot += (float) imDiffx; //set the yrot to yrot with the addition of the difference in the x position

	if(imXrot > imMaxAngle) //restrict maximum vertical camera angle to 45 degrees
		imXrot = imMaxAngle;
	else if(imXrot < imMinAngle) //restrict minimum vertical camera angle to 5 degrees
		imXrot = imMinAngle;
}


void InputManager::KeyOperations(void)
{
	if(imKeyStates['q']) // just a sample
	{
		cam.DirectionLookUD(1);
	}

	//Insert more KeyStates here


	if(imSpecialKeyStates[0])
	{
		imYrot += -1.0f;
	}
	
}