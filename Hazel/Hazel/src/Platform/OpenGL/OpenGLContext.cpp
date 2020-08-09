#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

#include "Hazel/Core.h"
#include "Hazel/Log.h"

namespace Hazel
{

OpenGLContext::OpenGLContext(GLFWwindow *pWindowHandle)
	: m_pWindowHandle(pWindowHandle)
{
	HZ_CORE_ASSERT(m_pWindowHandle, "Window handle is null");
}

void OpenGLContext::init()
{
	glfwMakeContextCurrent(m_pWindowHandle);
	const auto status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
	HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

	HZ_CORE_INFO("OpenGL Renderer:");
	HZ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
	HZ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
	HZ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
}

void OpenGLContext::swapBuffers()
{
	glfwSwapBuffers(m_pWindowHandle);
}

}
