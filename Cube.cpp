
#include "Cube.h"
#include <GL/glut.h>

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
    switch (key)
    {
		case GLUT_KEY_DOWN:      cubeY -= 5;        break;
		case GLUT_KEY_UP:      cubeY += 5;        break;
		case GLUT_KEY_LEFT:      cubeX -= 5;        break;
		case GLUT_KEY_RIGHT:      cubeX += 5;        break;
		case GLUT_KEY_F1:	rotAngle += 5;		break;

		default: break;
    }
}


void Cube::RotateCube()
{
	rotAngle += 100;
}

void Cube::DrawCube()
{
	glPushMatrix();
	glTranslatef(64, 64, 0);
        // Changes the position of the cube x, y, or z directions.
	glTranslatef(cubeX, cubeY, 0.0f);
        // Rotates the cube about the x,y or z axis depending where the '1' is specified in the parameters.
	glRotatef(rotAngle, 0, 0, 1);

	glBegin(GL_QUADS);
        // Defines each vertex of the cube.
        glVertex2f(-64.0,-64.0);
        glVertex2f(64.0,-64.0);
        glVertex2f(64.0,64.0);
        glVertex2f(-64.0,64.0);
        glVertex2f(-64.0,-64.0);
        glVertex2f(64.0,-64.0);
        glVertex2f(64.0,64.0);
        glVertex2f(-64.0,64.0);
    glEnd();

	glPopMatrix();
}
