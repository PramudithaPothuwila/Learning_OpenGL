#pragma once

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <GL/glew.h>


void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{

public:
	void Clear() const;
	void Draw(const VertexArray& vb, const IndexBuffer& ib, const Shader& shader) const;
};