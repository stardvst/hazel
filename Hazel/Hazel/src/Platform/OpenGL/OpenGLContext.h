#pragma once

#include "Hazel/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Hazel
{

class OpenGLContext : public GraphicsContext
{
public:
	explicit OpenGLContext(GLFWwindow *pWindowHandle);

	void init() override;
	void swapBuffers() override;

private:
	GLFWwindow *m_pWindowHandle = nullptr;
};

}
