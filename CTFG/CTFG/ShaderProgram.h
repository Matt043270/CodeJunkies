#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

class ShaderProgram
{
public:
	ShaderProgram();

	static void LoadProgram(string vertexProgram, string fragmentProgram, ShaderProgram &program);

	GLuint GetUniformLocation(string name);
	void StartProgram();
	void StopProgram();

private:
	void SetShaderId(GLuint shaderId);
	void SetVertexShaderId(GLuint shaderId);
	void SetFragmentShaderId(GLuint shaderId);
	static void LoadAndCompileShaderFromFile(string program, GLuint &programId, GLenum shaderType);
private:
	GLuint m_shaderId;
	GLuint m_vertexShaderId;
	GLuint m_fragmentShadeId;
};

#endif