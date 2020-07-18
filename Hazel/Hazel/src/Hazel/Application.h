#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"
#include "Window.h"

namespace Hazel
{

class WindowCloseEvent;
class ImGuiLayer;

// temporary, to disable warning C4251
template class HAZEL_API std::unique_ptr<Window>;

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
