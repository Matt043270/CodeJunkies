#include <iostream>
#include <vector>
#include "DisplayManager.h"
#include "StaticModel.h"
#include "ModelRenderer.h"
#include "Texture.h"

using namespace std;

int main(int argc, char* argv[])
{
	new DisplayManager();
	DisplayManager::DisplayHandle->Initialize(argc, argv);

	//vector<Vertex> vertexes = {Vertex(0.1f, 0.1f, 0), Vertex(0.9f, 0.1f, 0), Vertex(0.1f, 0.9f, 0), Vertex(0.9f, 0.9f, 0)};
	vector<Vertex> vertexes =
	{
		Vertex(Position(-0.9f, -0.9f, 0), Normal(0, 0, 0), TexCoord(0, 0)),
		Vertex(Position(0.9f, -0.9f, 0), Normal(0, 0, 0), TexCoord(1, 0)),
		Vertex(Position(-0.9f, 0.9f, 0), Normal(0, 0, 0), TexCoord(0, 1)),
		Vertex(Position(0.9f, 0.9f, 0), Normal(0, 0, 0), TexCoord(1, 1))
	};
	vector<int> ints = { 0, 1, 2, 2, 1, 3 };

	StaticModel model(vertexes, ints);
	Texture texTest("data/test.bmp");

	ModelRenderer renderer;
	renderer.AddModel(model);
	renderer.AddTexture(texTest);

	DisplayManager::DisplayHandle->RegisterRenderer(&renderer);

	DisplayManager::DisplayHandle->EnterMainGameLoop();
	cin.get();
}