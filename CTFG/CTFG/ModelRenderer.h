#ifndef MODELRENDERER_H
#define MODELRENDERER_H

#include "StaticModel.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include <iostream>

class ModelRenderer
{
public:
	ModelRenderer();
	~ModelRenderer();

	void AddModel(StaticModel model);
	void AddTexture(Texture texture);
	void Render();
private:

private:
	StaticModel m_model;
	Texture m_texture;
	ShaderProgram m_shader;
};

#endif