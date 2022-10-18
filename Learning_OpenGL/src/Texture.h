#pragma once
#include "Renderer.h"


class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_BPP;

public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0);
	void UnBind();

	inline int GetWidth() const { return m_width; }
	inline int GetHeight() const { return m_height; }
};
