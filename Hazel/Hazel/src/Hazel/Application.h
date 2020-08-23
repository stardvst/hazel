#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"
#include "Window.h"

#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/Buffer.h"

namespace Hazel
{

class WindowCloseEvent;
class ImGuiLayer;

class HAZEL_API Application
{
public:
	static Application &get();

	Application();
	virtual ~Application() = default;

	void run();

	void onEvent(Event &event);

	void pushLayer(Layer *pLayer);
	void pushOverlay(Layer *pOverlay);

	Window &getWindow();

private:
	bool onWindowClosed(const WindowCloseEvent &event);

	std::unique_ptr<Window> m_pWindow = nullptr;
	ImGuiLayer *m_pImGuiLayer = nullptr;
	bool m_bRunning = true;
	LayerStack m_layerStack;

	unsigned int m_nVertexArray = 0;
	std::unique_ptr<Shader> m_pShader = nullptr;
	std::unique_ptr<VertexBuffer> m_pVertexBuffer = nullptr;
	std::unique_ptr<IndexBuffer> m_pIndexBuffer = nullptr;

	static Application *s_pInstance;
};

inline Application &Application::get()
{
	return *s_pInstance;
}

inline Window &Application::getWindow()
{
	return *m_pWindow;
}

// To be defined in CLIENT
Application *createApplication();

}
