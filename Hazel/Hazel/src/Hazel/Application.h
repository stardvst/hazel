#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hazel
{

class HAZEL_API Application
{
public:
	Application();
	virtual ~Application() = default;

	void run();

private:
	std::unique_ptr<Window> m_pWindow = nullptr;
	bool m_bRunning = true;
};

// To be defined in CLIENT
Application *createApplication();

}
