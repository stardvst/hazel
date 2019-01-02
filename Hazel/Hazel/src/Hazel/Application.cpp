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

		for (auto pLayer : m_layerStack)
			pLayer->onUpdate();

		m_pWindow->onUpdate();
	}
}

void Application::onEvent(Event &event)
{
	EventDispatcher dispatcher(event);
	dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

	// layers are processed in reverse order during event processing
	for (auto layerIt = m_layerStack.end(); layerIt != m_layerStack.begin();)
	{
		(*--layerIt)->onEvent(event);
		if (event.bIsHandled)
			break;
	}
}

bool Application::onWindowClosed(const WindowCloseEvent &event)
{
	m_bRunning = false;
	return true;
}

void Application::pushLayer(Layer *pLayer)
{
	m_layerStack.pushLayer(pLayer);
}

void Application::pushOverlay(Layer *pOverlay)
{
	m_layerStack.pushOverlay(pOverlay);
}

}
