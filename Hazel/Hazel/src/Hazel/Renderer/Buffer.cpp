#include "hzpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Hazel/Log.h"

namespace Hazel
{

VertexBuffer *VertexBuffer::create(float *vertices, uint32_t size)
{
	switch (Renderer::getAPI())
	{
		case RendererAPI::None:
			HZ_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		default:
			break;
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}

IndexBuffer *IndexBuffer::create(uint32_t *indices, uint32_t size)
{
	switch (Renderer::getAPI())
	{
		case RendererAPI::None:
			HZ_CORE_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, size);
	}

	HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
	return nullptr;
}

}
