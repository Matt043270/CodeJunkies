
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Particle.h"
#include "Cube.h"

using namespace std;


    // Horizontal position of the cube.
Particle particles[1000];

    // Create the particles for the fountain:
void CreateParticles()
{
	for(int i = 0; i <= 1000; i++)
	{
		particles[i].CreateParticle();
	}
}

    // Allows for user input to control the particles.
static void special (int key, int x, int y)
{
    switch (key)
    {
		case GLUT_KEY_DOWN:
			CreateParticles();
			break;

		case GLUT_KEY_UP:
			for(int i = 0; i <= 1000; i++)
			{
				particles[i].SetG((float)particles[i].GetG()+0.01f);
			}
			break;

		default: break;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(int i = 0; i <= 1000; i++)
	{

		particles[i].DrawObjects();
	}

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void idle(void)
{
	for (int i = 0; i < 1000; i++)
	{
		particles[i].EvolveParticle();
	}

    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	CreateParticles();

	glutInitWindowSize(512,512);
	glutInitWindowPosition(100,100);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("OpenGL Particle System");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 512.0, 0.0, 512.0);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutSpecialFunc(special);
	glutMainLoop();

	return EXIT_SUCCESS;
}
