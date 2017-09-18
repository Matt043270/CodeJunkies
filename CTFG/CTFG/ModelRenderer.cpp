#include "ModelRenderer.h"

ModelRenderer::ModelRenderer()
{
	glClearColor(100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f, 1.0f);
	ShaderProgram::LoadProgram("data/vertShader.vert", "data/fragShader.frag", m_shader);
}

ModelRenderer::~ModelRenderer()
{

}

void ModelRenderer::AddModel(StaticModel model)
{
	m_model = model;
}

void ModelRenderer::AddTexture(Texture tex)
{
	m_texture = tex;
}

void ModelRenderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	m_shader.StartProgram();

	m_model.BindVertexAttribArray();
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glActiveTexture(GL_TEXTURE0);
	m_texture.BindTexture();
	glDrawElements(GL_TRIANGLES, m_model.GetIndiceCount(), GL_UNSIGNED_INT, 0);

	m_shader.StopProgram();

	glutSwapBuffers();
}