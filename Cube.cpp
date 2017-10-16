
#include "Cube.h"
#include <freeglut.h>

    /* Moves the cube 512 pixels every second. When it reaches the other side of the window
    it goes back to the start.*/

Cube::Cube()
{
	cubeX = 0;
	cubeY = 0;
	rotAngle = 0;
	lastFrameTime = 0;
}


    // This method moves the cube
void Cube::MoveCube()
{
	if (lastFrameTime == 0)
    {
        lastFrameTime = glutGet(GLUT_ELAPSED_TIME);
    }
	int now = glutGet(GLUT_ELAPSED_TIME);
    int elapsedMilliseconds = now - lastFrameTime;
    float elapsedTime = elapsedMilliseconds / 1000.0f;
    lastFrameTime = now;
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    cubeX *= 512.0f * elapsedTime;
    if (cubeX > windowWidth)
    {
        cubeX -= windowWidth;
    }
}

    // Moves (translates) the position of the cube.
void Cube::TranslateCube(int key)
{
    
}


void Cube::RotateCube()
{
	rotAngle += 100;
}

void Cube::DrawCube()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(64, 64, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
        // Changes the position of the cube x, y, or z directions.
	glTranslatef(cubeX, cubeY, 0.0f);
        // Rotates the cube about the x,y or z axis depending where the '1' is specified in the parameters.
	glRotatef(rotAngle, 0, 0, 1);

	/*glBegin(GL_QUADS);
        // Defines each vertex of the cube.
        glVertex2f(-64.0,-64.0);
        glVertex2f(64.0,-64.0);
        glVertex2f(64.0,64.0);
        glVertex2f(-64.0,64.0);
        glVertex2f(-64.0,-64.0);
        glVertex2f(64.0,-64.0);
        glVertex2f(64.0,64.0);
        glVertex2f(-64.0,64.0);
    glEnd();*/
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
