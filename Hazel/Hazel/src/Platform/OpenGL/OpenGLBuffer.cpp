#include "hzpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Hazel
{

//////////////////////////////////////////////////////////////////////////
// class OpenGLVertexBuffer
//
OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size)
{
	glCreateBuffers(1, &m_nRendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);

	// upload to GPU (from CPU)
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_nRendererID);
}

void OpenGLVertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_nRendererID);
}

void OpenGLVertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//////////////////////////////////////////////////////////////////////////
// class OpenGLIndexBuffer
//
OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t *indices, uint32_t count)
	: m_nCount(count)
{
	glCreateBuffers(1, &m_nRendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_nRendererID);

	// upload to GPU (from CPU)
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_nCount * sizeof(indices), indices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_nRendererID);
}

void OpenGLIndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_nRendererID);
}

void OpenGLIndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32_t OpenGLIndexBuffer::count() const
{
	return m_nCount;
}

}
