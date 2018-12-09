#include "hzpch.h"
#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel
{

void Application::run()
{
	const WindowResizeEvent event{ 1280, 720 };
	if (event.isInCategory(App))
	{
		HZ_TRACE(event);
	}
	if (event.isInCategory(Input))
	{
		HZ_TRACE(event);
	}

	while (true);
}

}