#pragma once

#include "Hazel/Renderer/Buffer.h"

namespace Hazel
{

class OpenGLVertexBuffer : public VertexBuffer
{
public:
	OpenGLVertexBuffer(float *vertices, uint32_t size);
	~OpenGLVertexBuffer() override;

	void bind() const override;
	void unbind() const override;

private:
	uint32_t m_nRendererID;
};

class OpenGLIndexBuffer : public IndexBuffer
{
public:
	OpenGLIndexBuffer(uint32_t *indices, uint32_t size);
	~OpenGLIndexBuffer() override;

	void bind() const override;
	void unbind() const override;

	uint32_t count() const override;

private:
	uint32_t m_nRendererID;
	uint32_t m_nCount = 0;
};

}
