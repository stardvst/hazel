#pragma once

namespace Hazel
{

class Shader
{
public:
	Shader(const std::string &sVertexSrc, const std::string &sFragmentSrc);
	~Shader();

	void bind() const;
	void unbind() const;

private:
	uint32_t m_nRendererID;
};

}
