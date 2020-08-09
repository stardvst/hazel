#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "Input.h"

#include "ImGui/ImGuiLayer.h"

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

	m_pImGuiLayer = new ImGuiLayer;
	pushOverlay(m_pImGuiLayer);

	glGenVertexArrays(1, &m_nVertexArray);
	glBindVertexArray(m_nVertexArray);

	glGenBuffers(1, &m_nVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_nVertexBuffer);

	float vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	// upload to GPU (from CPU)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// tell GPU layout of data
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	glGenBuffers(1, &m_nIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_nIndexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Application::run()
{
	while (m_bRunning)
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(m_nVertexArray);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		for (auto pLayer : m_layerStack)
			pLayer->onUpdate();

		m_pImGuiLayer->begin();
		for (auto pLayer : m_layerStack)
			pLayer->onImGuiRender();
		m_pImGuiLayer->end();

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
