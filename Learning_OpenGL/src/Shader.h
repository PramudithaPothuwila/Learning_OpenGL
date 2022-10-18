#pragma once
#include <string>
#include <iostream>
#include <Gl/glew.h>
#include <fstream>
#include <sstream>
#include <unordered_map>


struct ShaderProgramSource
{
	std::string VertexShader;
	std::string FragementShader;
};

class Shader
{
private:
	std::string m_Filepath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	ShaderProgramSource ParseShader();
	unsigned int CompileShader(unsigned int type, const std::string source);
	unsigned int CreateShader(const std::string& vertexShader, std::string fragmentShader);
	int GetUniformLocation(const std::string& name);
};
