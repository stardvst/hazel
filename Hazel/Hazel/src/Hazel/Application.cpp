#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "Input.h"

#include <glad/glad.h>

namespace Hazel
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application *Application::s_pInstance = nullptr;

Application::Application()
{
	HZ_CORE_ASSERT(!s_pInstance, "Application already exists!");

	s_pInstance = this;

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

		auto [x, y] = Input::getMousePosition();
		HZ_CORE_TRACE("{0}, {1}", x, y);

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
	pLayer->onAttach();
}

void Application::pushOverlay(Layer *pOverlay)
{
	m_layerStack.pushOverlay(pOverlay);
	pOverlay->onAttach();
}

}
