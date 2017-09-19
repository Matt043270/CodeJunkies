#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
	DisplayHandle = this;
	m_renderer = nullptr;
}

DisplayManager::~DisplayManager()
{
	delete DisplayHandle;
	delete m_renderer;
}

bool DisplayManager::Initialize(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_CORE_PROFILE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	glutCreateWindow("FreeGLUT");
	glutDisplayFunc(Update);
	glutIdleFunc(Update);


	glewInit();

	glEnable(GL_TEXTURE_2D);

	return true;
}

void DisplayManager::Update()
{
	if (DisplayHandle->m_renderer != nullptr)
	{
		DisplayHandle->m_renderer->Render();
	}
}

void DisplayManager::Destroy()
{

}

void DisplayManager::RegisterRenderer(ModelRenderer * renderer)
{
	m_renderer = renderer;
}

void DisplayManager::EnterMainGameLoop()
{
	glutMainLoop();
}

DisplayManager * DisplayManager::DisplayHandle = nullptr;