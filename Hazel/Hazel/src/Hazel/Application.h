#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hazel
{

class HAZEL_API Application
{
public:
	Application() = default;
	virtual ~Application() = default;

	void run();
};

// To be defined in CLIENT
Application *createApplication();

}