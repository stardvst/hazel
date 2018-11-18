#pragma once

#include "Core.h"

namespace Hazel
{

class HAZEL_API Application
{
public:
	Application() = default;
	virtual ~Application() = default;

	static void run();
};

// To be defined in CLIENT
Application *createApplication();

}