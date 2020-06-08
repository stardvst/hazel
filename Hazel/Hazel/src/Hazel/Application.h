#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"
#include "Window.h"

namespace Hazel
{
class WindowCloseEvent;

// temporary, to disable warning C4251
template class HAZEL_API std::unique_ptr<Window>;

class HAZEL_API Application
{
public:
	Application();
	virtual ~Application() = default;

	void run();

	void onEvent(Event &event);

	void pushLayer(Layer *pLayer);
	void pushOverlay(Layer *pOverlay);

private:
	bool onWindowClosed(const WindowCloseEvent &event);

	std::unique_ptr<Window> m_pWindow = nullptr;
	bool m_bRunning = true;
	LayerStack m_layerStack;
};

// To be defined in CLIENT
Application *createApplication();

}
