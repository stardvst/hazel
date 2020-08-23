#pragma once

namespace Hazel
{

enum class RendererAPI
{
	None,
	OpenGL
};

class Renderer
{
public:
	static RendererAPI getAPI();

private:
	static RendererAPI s_nRendererAPI;
};

inline RendererAPI Renderer::getAPI()
{
	return s_nRendererAPI;
}

}
