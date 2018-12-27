#include "hzpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Hazel
{

Application::Application()
{
	m_pWindow = std::unique_ptr<Window>(Window::create());
}

void Application::run()
{
	while (m_bRunning)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_pWindow->onUpdate();
	}
}

}