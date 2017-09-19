#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{

}

void ShaderProgram::LoadProgram(string vertexProgram, string fragmentProgram, ShaderProgram &program)
{
	ShaderProgram sp;
	GLuint vertShaderId, fragShaderId;

	LoadAndCompileShaderFromFile(vertexProgram, vertShaderId, GL_VERTEX_SHADER);
	LoadAndCompileShaderFromFile(fragmentProgram, fragShaderId, GL_FRAGMENT_SHADER);

	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertShaderId);
	glAttachShader(programId, fragShaderId);
	glBindAttribLocation(programId, 0, "position");
	glBindAttribLocation(programId, 1, "textureCoords");
	glLinkProgram(programId);

	program.SetFragmentShaderId(fragShaderId);
	program.SetVertexShaderId(vertShaderId);
	program.SetShaderId(programId);
}

void ShaderProgram::LoadAndCompileShaderFromFile(string program, GLuint &programId, GLenum shaderType)
{
	string shaderContent, line = "";
	ifstream fileStream(program);
	if (!fileStream.is_open())
	{
		cout << program << " shader failed to open." << endl;
		return;
	}
	while (getline(fileStream, line))
	{
		shaderContent.append(line + '\n');
	}
	fileStream.close();

	programId = glCreateShader(shaderType);
	const char * shaderSource = shaderContent.c_str();
	cout << program << " loaded successfully. Compiling..." << endl;
	glShaderSource(programId, 1, &shaderSource, NULL);
	glCompileShader(programId);
	GLint compileStatus = GL_FALSE;
	glGetShaderiv(programId, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE)
	{
		cout << program << " failed to compile." << endl;
	}
	else
	{
		cout << program << " compiled successfully." << endl;
	}
}

void ShaderProgram::SetFragmentShaderId(GLuint shaderId)
{
	m_fragmentShadeId = shaderId;
}

void ShaderProgram::SetVertexShaderId(GLuint shaderId)
{
	m_vertexShaderId = shaderId;
}

void ShaderProgram::SetShaderId(GLuint shaderId)
{
	m_shaderId = shaderId;
}

void ShaderProgram::StartProgram()
{
	glUseProgram(m_shaderId);
}

void ShaderProgram::StopProgram()
{
	glUseProgram(0);
}

GLuint ShaderProgram::GetUniformLocation(string name)
{
	const char * cName = name.c_str();
	return glGetUniformLocation(m_shaderId, cName);
}