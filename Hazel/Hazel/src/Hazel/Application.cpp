#include "hzpch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace Hazel
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application::Application()
{
	m_pWindow = std::unique_ptr<Window>(Window::create());
	m_pWindow->setEventCallback(BIND_EVENT_FN(onEvent));
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

void Application::onEvent(Event &event)
{
	EventDispatcher dispatcher(event);
	dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));
	
	HZ_CORE_TRACE("{0}", event);
}

bool Application::onWindowClosed(const WindowCloseEvent &event)
{
	m_bRunning = false;
	return true;
}

}
