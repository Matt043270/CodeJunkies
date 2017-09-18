#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
//#define NDEBUG

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ModelRenderer.h"

using namespace std;

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	bool Initialize(int argc, char* argv[]);
	static void Update();
	void Destroy();
	void RegisterRenderer(ModelRenderer * renderer);
	void EnterMainGameLoop();

	const int DISPLAY_WIDTH = 1280;
	const int DISPLAY_HEIGHT = 720;


	static DisplayManager * DisplayHandle;
private:

private:
	ModelRenderer * m_renderer;
};


#endif