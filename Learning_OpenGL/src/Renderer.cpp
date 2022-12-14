#include "Renderer.h"


void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error (" << error << ")" << " function: "<< function << " file: " << file << " line:" << line << std::endl;
		return false;
	}
	return true;
}


void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr))
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}
